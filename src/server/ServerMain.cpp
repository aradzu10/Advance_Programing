#include "Server.h"
#include "../client/ConnectionSettings.h"

int main() {
    ConnectionSettings settings;
    settings.Setup();
    Server newServer(settings.GetPort());
    newServer.start();
    newServer.stop();
    return 0;
}