/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "Server.h"
#include "../ConnectionSettings.h"

int main() {
    ConnectionSettings settings;
    settings.Setup();
    Server newServer(settings.GetPort(), settings.GetMaxDataSizeTransfer());
    newServer.start();
    newServer.stop();
    return 0;
}