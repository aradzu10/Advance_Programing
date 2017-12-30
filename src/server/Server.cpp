/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#define MAX_CONNECTIONS 10

#include "Server.h"
#include "MatchManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <pthread.h>

struct ServerAndClientSocket {
    Server* server;
    int ClientSocket;
};

Server::Server(int port, int max) : port(port), maxDataSizeToTransfer(max), matchManager(max) {
    commandManager.setMatchManager(matchManager);
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

static void *AcceptClient_Thread(void *context) {
    return ((Server *)context)->AcceptClient(NULL);
}

static void *HandleClient_Thread(void *context) {
    struct ServerAndClientSocket *args = (struct ServerAndClientSocket*) context;
    return args->server->HandleClient((void*) args->ClientSocket);
}

void* Server::AcceptClient(void* nothing) {
    pthread_t threadsAcceptClient;
    pthread_t threadsHandleClient;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = 0;
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    int rc = pthread_create(&threadsAcceptClient, NULL, AcceptClient_Thread, this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        pthread_exit(NULL);
    }
    struct ServerAndClientSocket args;
    args.server = this;
    args.ClientSocket = clientSocket;
    rc = pthread_create(&threadsHandleClient, NULL, HandleClient_Thread, &args);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        pthread_exit(NULL);
    }
}

void* Server::HandleClient(void* clientT) {
    long client = (long)clientT;
    char buffer[maxDataSizeToTransfer];
    while(true) {
        memset(buffer, 0, maxDataSizeToTransfer);
        int check = read(client, buffer, maxDataSizeToTransfer);
        if (check <= 0) {
            pthread_exit(NULL);
        }
        if (commandManager.DoCommand(buffer, client) == 0) {
            strcpy(buffer, "success");
            check = send(client, buffer, maxDataSizeToTransfer, 0);
            if (check <= 0) {
                pthread_exit(NULL);
            }
            break;
        } else {
            strcpy(buffer, "failed");
            check = send(client, buffer, maxDataSizeToTransfer, 0);
            if (check <= 0) {
                pthread_exit(NULL);
            }
        }
    }
}
