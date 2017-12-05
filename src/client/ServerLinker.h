#ifndef SERVER_LINKER_
#define SERVER_LINKER_


class ServerLinker {
public:
    ServerLinker(const char *serverIP, int serverPort);
    void connectToServer();
private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
};


#endif //SERVER_LINKER_
