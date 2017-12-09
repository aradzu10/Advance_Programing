/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "ServerLinker.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include "../ConnectionSettings.h"

ServerLinker::ServerLinker() : clientSocket(0) {
    ConnectionSettings settings;
    settings.Setup();
    serverIP = settings.GetIPaddress();
    serverPort = settings.GetPort();
    maxDataSize = settings.GetMaxDataSizeTransfer();

}

ServerLinker::ServerLinker(const std::string& serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {}

ServerLinker::~ServerLinker() {
    close(clientSocket);
}

void ServerLinker::ConnectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;
    if (!inet_aton(serverIP.c_str(), &address)) {
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
    char *buffer = new char[maxDataSize];
    memset(buffer, 0, maxDataSize);
    int check = read(clientSocket, buffer, maxDataSize);
    if (check < 0) {
        throw "Error reading data";
    }
    return buffer;
}

void ServerLinker::WriteDataToServer(const char *buffer, int size) {
    int check = send(clientSocket, buffer, size, 0);
    if (check < 0) {
        throw "Error reading data";
    }
}
