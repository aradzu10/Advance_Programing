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

class Server {

public:

    Server(int port, int max);

    ~Server();

    void Start();
    void* AcceptClient(void* nothing);
    //close server
    void Stop();
    void* HandleClient(void* client);

private:
    //members
    int port;
    int maxDataSizeToTransfer;
    int serverSocket;
    MatchManager matchManager;
    CommandManager commandManager;
};


#endif //SERVER_H
