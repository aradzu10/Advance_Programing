/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef SERVER_H
#define SERVER_H


#include "MatchManager.h"
#include "CommandManager.h"
#include "TheardPool.h"

class Server {

public:

    Server(int port, int max);

    ~Server();
    // start server
    void Start();
    // accept new client (in new thread)
    void* AcceptClient(void* nothing);
    // close server
    void Stop();
    // handle new client (in new thread)
    void* HandleClient(void* client);

private:
    // members
    int port;
    int maxDataSizeToTransfer;
    int serverSocket;
    MatchManager matchManager;
    CommandManager commandManager;
    ThreadPool threadPool;

};


#endif //SERVER_H
