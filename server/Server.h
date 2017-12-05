#ifndef SERVER_H
#define SERVER_H

class Server {
public:
    Server(int port_);
    void start();
    void stop();
private:
    int port;
    int serverSocket;
    void InitiateServer();
    void ConnectToPlayers();
    void StartGame();
    void TransferPoint(int sender, int receiver);
    void CheckIfEndOfSession();
};
#endif //SERVER_H
