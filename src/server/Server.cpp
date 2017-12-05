#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MAX_CONNECTIONS 2
#define MAX_SIZE_OF_DATA 1024

Server::Server(int port_) : port(port_), serverSocket(0) {
}

void Server::start() {
    InitiateServer();
    listen(serverSocket, MAX_CONNECTIONS);
    int player1 = ConnectToPlayer();
    int player2 = ConnectToPlayer();
    InitiatePlayers(player1, player2);
    CommunicationStream(player1, player2);
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
        throw "Error on binding";
    }
}

int Server::ConnectToPlayer() {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    if (clientSocket < 0) {
        throw "Error on accept";
    }
    return clientSocket;
}

void Server::InitiatePlayers(int player1, int player2) {
    int white = 1;
    int black = 2;
    if (write(player1, &white, sizeof(white)) < 0) {
        throw "Error on Initiate player1";
    }

    if (write(player2, &black, sizeof(black)) < 0) {
        throw "Error on Initiate player2";
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
    char buffer[MAX_SIZE_OF_DATA] = "\0";
    int check = read(sender, buffer, sizeof(buffer));
    if (check <= 0) {
        false;
    }
    check = write(receiver, buffer, sizeof(buffer));
    if (check <= 0) {
        false;
    }
    return true;
}