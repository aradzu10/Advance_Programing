/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef SERVER_H
#define SERVER_H

//server.
class Server {
public:
    //set port of server
    Server(int port_, int maxData);
    //start server
    void start();
    //close server
    void stop();

private:
    //initiate server - create socket, bind and listening
    void InitiateServer();
    //send to player their color - 1, 2
    void InitiatePlayers(int player1, int player2);
    //call transfer data between sender and receiver, and switch between sender and receiver
    void CommunicationStream(int player1, int player2);
    //transfer data
    bool TransferData(int sender, int receiver);

private:
    //members
    int port;
    int maxDataSizeToTransfer;
    int serverSocket;
};
#endif //SERVER_H
