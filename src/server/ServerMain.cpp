/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "MatchHandler.h"
#include "../connectionSetting/ConnectionSettings.h"

int main() {
    ConnectionSettings settings("connection_settings_server.txt");
    settings.Setup();
    MatchHandler newServer(settings.GetPort(), settings.GetMaxDataSizeTransfer());
    newServer.start();
    newServer.stop();
    return 0;
}
