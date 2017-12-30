/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <cstring>
#include "../connectionSetting/ConnectionSettings.h"
#include "Server.h"

void StartOperation(Server server) {
    server.Start();
}

void CloseOperation(Server server) {
    string input;
    while (true) {
        cin >> input;
        if (strcmp(input, "exit") == 0) {
            server.Stop();
            break;
        }
    }
}

int main() {
    ConnectionSettings settings("connection_settings_server.txt");
    settings.Setup();
    Server server(settings.GetPort(), settings.GetMaxDataSizeTransfer());
    // add - thread here
    StartOperation(server);
    // add - thread here
    CloseOperation(server);
    return 0;
}
