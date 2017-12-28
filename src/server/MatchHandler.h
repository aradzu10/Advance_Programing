/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef MATCH_HANDLER_H
#define MATCH_HANDLER_H

#include <iostream>
using namespace std;

//server.
class MatchHandler {
public:
    //set port of server
    MatchHandler(int max);

    ~MatchHandler();

    void setClientSocket1(int clientSocket1);

    void setClientSocket2(int clientSocket2);
    //start server
    void Start();
    //close server
    void Close();

private:
    //send to player their color - 1, 2
    void InitiatePlayers();
    //call transfer data between sender and receiver, and switch between sender and receiver
    void CommunicationStream();
    //transfer data
    bool TransferData(int sender, int receiver);

private:
    //members
    int clientSocket1;
    int clientSocket2;
    int maxDataSizeToTransfer;

};
#endif //MATCH_HANDLER_H
