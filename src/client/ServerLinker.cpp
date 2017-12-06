#include "ServerLinker.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

#define MAX_SIZE_OF_DATA 81920

ServerLinker::ServerLinker(const char *serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {}

void ServerLinker::ConnectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    struct sockaddr_in serverAddress;
    memset((char*)&address, 0, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, server->h_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
}

char *ServerLinker::ReadDataFromServer() {
    char *buffer = new char[MAX_SIZE_OF_DATA];
    memset(buffer, 0, MAX_SIZE_OF_DATA);
    int check = read(clientSocket, buffer, MAX_SIZE_OF_DATA);
    std::cout << buffer << " 9" << std::endl;
    if (check < 0) {
        throw "Error reading data";
    }
    return buffer;
}

void ServerLinker::WriteDataToServer(char *buffer, int size) {
    std::cout << buffer << " 10" << std::endl;
    int check = send(clientSocket, buffer, size, 0);
    if (check < 0) {
        throw "Error reading data";
    }
}
