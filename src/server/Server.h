#ifndef SERVER_H
#define SERVER_H

class Server {
public:
    Server(int port_);
    void start();
    void tryServer();
    void stop();
private:
    int port;
    int serverSocket;
    void InitiateServer();
    void InitiatePlayers(int player1, int player2);
    void CommunicationStream(int player1, int player2);
    bool TransferData(int sender, int receiver);
};
#endif //SERVER_H
