/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef SERVER_LINKER_
#define SERVER_LINKER_

#include <iostream>

//client. talk with the server. read and send data
class ServerLinker {
public:
    //analise ip and port from file
    ServerLinker();
    //get ip and port
    ServerLinker(const std::string& serverIP, int serverPort);
    ~ServerLinker();
    //connect to server
    void ConnectToServer();
    //read data from server
    char* ReadDataFromServer();
    //send data to server
    void WriteDataToServer(const char* buffer, int size);
private:
    //members
    int clientSocket;
    int maxDataSize;
    int serverPort;
    std::string serverIP;
};


#endif //SERVER_LINKER_
