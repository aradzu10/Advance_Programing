#include "client/ServerLinker.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {

    ServerLinker serverLinker("127.0.0.1", 8981);
    serverLinker.ConnectToServer();
    std::cout << "connected to server" << std::endl;
    char* x = serverLinker.ReadDataFromServer();
    std::cout << x << std::endl;
    char* y;
    if (*x == '2') {
        y = serverLinker.ReadDataFromServer();
        std::cout << y << std::endl;
    } else if (*x == '1') {
        serverLinker.WriteDataToServer("well hello there", 81920);
    }
}