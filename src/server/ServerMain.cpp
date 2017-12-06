#include "Server.h"

int main() {
    Server newServer(8981); // change - read port from file
    newServer.start();
    newServer.stop();
    return 0;
}