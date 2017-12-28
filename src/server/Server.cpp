/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#define MAX_CONNECTIONS 10

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>

Server::Server() {

}

Server::~Server() {

}

void Server::Start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    memset((void *) &serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        close(serverSocket);
        throw "Error on binding";
    }
    if (listen(serverSocket, MAX_CONNECTIONS) < 0) {
        close(serverSocket);
        throw "Error on listening";
    }
}

void Server::Stop() {
    close(serverSocket);
}

void Server::AcceptClient() {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = 0;
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    // add - thread for "AcceptClient"
    if (clientSocket < 0) {
        close(serverSocket);
        throw "Error on accept";
    }



}
