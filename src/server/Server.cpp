/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#define MAX_CONNECTIONS 10
#define NUM_THEARDS 5

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
    long ClientSocket;
};
typedef struct ServerAndClientSocket ServerAndClientSocket;

Server::Server(int port, int max) : port(port), maxDataSizeToTransfer(max), matchManager(max), threadPool(NUM_THEARDS) {
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
    threadPool.terminate();
    close(serverSocket);
}

static void *AcceptClient_Thread(void *context) {
    return ((Server *)context)->AcceptClient(NULL);
}

static void *HandleClient_Thread(void *context) {
    ServerAndClientSocket *args = (ServerAndClientSocket*) context;
    return args->server->HandleClient(context);
}

void* Server::AcceptClient(void* nothing) {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = 0;
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    Task *acceptClient = new Task(AcceptClient_Thread, this);
    threadPool.addTask(acceptClient);
    if (clientSocket < 1) {
        cout << "Error: connecting to client" << endl;
    }
    ServerAndClientSocket *args = new ServerAndClientSocket();
    args->server = this;
    args->ClientSocket = clientSocket;
    cout << "1: " << clientSocket << endl;
    cout << "1: " << args->ClientSocket << endl;
    Task *handleClient = new Task(HandleClient_Thread, args);
    threadPool.addTask(handleClient);
}

void* Server::HandleClient(void* clientT) {
    ServerAndClientSocket *args = (ServerAndClientSocket*) clientT;
    long client = args->ClientSocket;
    delete args;
    cout << "2: " << client << endl;
    char buffer[maxDataSizeToTransfer];
    while(true) {
        memset(buffer, 0, maxDataSizeToTransfer);
        int check = read(client, buffer, maxDataSizeToTransfer);
        if (check < 0) {
            cout << "Error with client: " << client << endl;
            break;
        }
        int ans = commandManager.DoCommand(buffer, client);
        if (ans != 0 && ans != 1) {
            continue;
        }
        string msg;
        if (ans == 0) {
            msg = "success";
        } else if (ans == 1){
            msg = "failed";
        }
        int size = msg.size() + 1;
        check = send(client, &size, sizeof(size), 0);
        if (check <= 0) {
            break;
        }
        send(client, msg.c_str(), msg.size(), 0);
        break;
    }
}
