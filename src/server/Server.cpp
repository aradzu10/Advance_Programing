/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>

#define MAX_CONNECTIONS 2

Server::Server(int port_, int maxData) : port(port_), serverSocket(0), maxDataSizeToTransfer(maxData) {
}

void Server::start() {
    InitiateServer();

    while (true) {
        struct sockaddr_in clientAddress1;
        struct sockaddr_in clientAddress2;
        socklen_t clientAddressLen1 = 0;
        socklen_t clientAddressLen2 = 0;
        int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress1, &clientAddressLen1);
        if (clientSocket1 < 0) {
            close(serverSocket);
            throw "Error on accept";
        }
        int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress2, &clientAddressLen2);
        if (clientSocket2 < 0) {
            close(serverSocket);
            throw "Error on accept";
        }

        InitiatePlayers(clientSocket1, clientSocket2);
        CommunicationStream(clientSocket1, clientSocket2);
    }
}

void Server::stop() {
    close(serverSocket);
}

void Server::InitiateServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    memset((void *)&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        close(serverSocket);
        throw "Error on binding";
    }
    if (listen(serverSocket, MAX_CONNECTIONS) < 0) {
        close(serverSocket);
        throw "Error on listening";
    }
}

void Server::InitiatePlayers(int player1, int player2) {
    std::string black = "1";
    std::string white = "2";
    if (send(player1, black.c_str(), sizeof(black), 0) < 0) {
        throw "Error on Initiate player2";
    }
    if (send(player2, white.c_str(), sizeof(white), 0) < 0) {
        throw "Error on Initiate player1";
    }

}

void Server::CommunicationStream(int player1, int player2) {
    int sender = player1;
    int receiver = player2;
    int tmp;
    while (TransferData(sender, receiver)) {
        tmp = sender;
        sender = receiver;
        receiver = tmp;
    }
    close(player1);
    close(player2);
}

bool Server::TransferData(int sender, int receiver) {
    char buffer[maxDataSizeToTransfer];
    memset(buffer, 0, maxDataSizeToTransfer);
    int check = read(sender, buffer, maxDataSizeToTransfer);
    if (check <= 0) {
        return false;
    }
    check = send(receiver, buffer, maxDataSizeToTransfer, 0);
    if (check <= 0) {
        return false;
    }
    return true;
}
