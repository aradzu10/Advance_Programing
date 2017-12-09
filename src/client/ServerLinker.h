#ifndef SERVER_LINKER_
#define SERVER_LINKER_

#include <iostream>

class ServerLinker {
public:
    ServerLinker();
    ServerLinker(const std::string& serverIP, int serverPort);
    ~ServerLinker();
    void ConnectToServer();
    char* ReadDataFromServer();
    void WriteDataToServer(const char* buffer, int size);
private:
    std::string serverIP;
    int serverPort;
    int clientSocket;
};


#endif //SERVER_LINKER_
