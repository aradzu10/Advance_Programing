#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Server::Server(int port_) : port(port_), serverSocket(0) {
}

void Server::start() {

    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        handleClient(clientSocket);
        // Close communication with the client
        close(clientSocket);
}

void Server::stop() {

}

void Server::InitiateServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,
          sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
}

void Server::ConnectToPlayers() {

}

void Server::StartGame() {

}

void Server::TransferPoint(int sender, int receiver) {

}

void Server::CheckIfEndOfSession() {

}
