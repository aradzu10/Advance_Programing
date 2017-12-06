#include "Server.h"

int main() {
    Server newServer(8989); // change - read port from file
    newServer.tryServer();
    newServer.stop();
    return 0;
}