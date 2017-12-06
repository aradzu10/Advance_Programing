#include "client/ServerLinker.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    ServerLinker serverLinker("127.0.0.1", 8989);
    serverLinker.ConnectToServer();
    std::cout << "connected to server" << std::endl;
    char* x = serverLinker.ReadDataFromServer();
    std::cout << *x << std::endl;
    char* y;
    if (*x == 2) {
        y = serverLinker.ReadDataFromServer();
        std::cout << *y << std::endl;
    } else if (*x == 1) {
        serverLinker.WriteDataToServer("well hello there", 1024);
    }
}