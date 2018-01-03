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
#include "../connectionSetting/ConnectionSettings.h"
#include <iostream>
using namespace std;

ServerLinker::ServerLinker() : clientSocket(0), connnectedToServer(false) {
    ConnectionSettings settings("connection_settings_client.txt");
    settings.Setup();
    serverIP = settings.GetIPaddress();
    serverPort = settings.GetPort();
    maxDataSize = settings.GetMaxDataSizeTransfer();

}

ServerLinker::ServerLinker(const std::string& serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0), connnectedToServer(false) {}

ServerLinker::~ServerLinker() {
    close(clientSocket);
}

bool ServerLinker::isConnnectedToServer() const {
    return connnectedToServer;
}

void ServerLinker::ConnectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket <= 0) {
        cout <<  "Error opening socket" << endl;
        return;
    }
    struct in_addr address;
    if (!inet_aton(serverIP.c_str(), &address)) {
        cout <<  "Can't parse IP address" << endl;
        return;
    }
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        cout <<  "Host is unreachable" << endl;
        return;
    }
    struct sockaddr_in serverAddress;
    memset((char*)&address, 0, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, server->h_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) <= 0) {
        cout <<  "Error connecting to server" << endl;
        return;
    }
    connnectedToServer = true;
}

int ServerLinker::ReadNumberFromServer() {
    int num = -1;
    int check = read(clientSocket, &num, sizeof(num));
    if (check <= 0) {
        connnectedToServer = false;
    }

    return num;
}

char *ServerLinker::ReadDataFromServer() {
    return ReadDataFromServer(maxDataSize);
}

char *ServerLinker::ReadDataFromServer(int size) {
    if (size < 1) {
        return new char[1];
    }
    char *buffer = new char[size];
    memset(buffer, 0, size);
    int check = read(clientSocket, buffer, size);
    if (check <= 0) {
        connnectedToServer = false;
    }

    return buffer;
}

void ServerLinker::WriteDataToServer(const char *buffer, int size) {
    int check = send(clientSocket, buffer, size, 0);
    if (check <= 0) {
        connnectedToServer = false;
    }
}
