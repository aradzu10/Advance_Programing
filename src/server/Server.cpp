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
#include <sstream>

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
    matchManager.CloseAll();
    pthread_cancel(threadsAcceptClient);
    pthread_join(threadsAcceptClient, NULL);
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
    pthread_t threadsHandleClient;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = 0;
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    int rc = pthread_create(&threadsAcceptClient, NULL, AcceptClient_Thread, this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
    }
    if (clientSocket < 1) {
        cout << "Error: connecting to client" << endl;
    }
    struct ServerAndClientSocket args;
    args.server = this;
    args.ClientSocket = clientSocket;
    cout << "1: " << clientSocket << endl;
    cout << "1: " << args.ClientSocket << endl;
    rc = pthread_create(&threadsHandleClient, NULL, HandleClient_Thread, &args);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
    }
    pthread_detach(pthread_self());
}

void* Server::HandleClient(void* clientT) {
    int client = *((int*)(&clientT));
    cout << "2: " << client << endl;
    char buffer[maxDataSizeToTransfer];
    while(true) {
        memset(buffer, 0, maxDataSizeToTransfer);
        int check = read(client, buffer, maxDataSizeToTransfer);
        if (check < 0) {
            cout << "not good: " << client << endl;
            break;
        }
        int ans = commandManager.DoCommand(buffer, client);
        if (ans == 0) {
            string msg = "success";
            int size = msg.size();
            check = send(client, &size, sizeof(size), 0);
            if (check <= 0) {
                break;
            }
            send(client, msg.c_str(), msg.size(), 0);
            break;
        } else if (ans == 1){
            string msg = "failed";
            int size = msg.size();
            check = send(client, &size, sizeof(size), 0);
            if (check <= 0) {
                break;
            }
            check = send(client, msg.c_str(), msg.size(), 0);
            if (check <= 0) {
                break;
            }
        }
    }
    pthread_detach(pthread_self());
}
