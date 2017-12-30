/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <cstring>
#include <pthread.h>
#include "../connectionSetting/ConnectionSettings.h"
#include "Server.h"

void* StartOperation(void* serverV) {
    Server *server = (Server*) serverV;
    server->Start();
    server->AcceptClient(NULL);
}

void CloseOperation(Server* server) {
    string input;
    while (true) {
        cin >> input;
        if (strcmp(input.c_str(), "exit") == 0) {
            server->Stop();
            break;
        }
    }
}

int main() {
    pthread_t threads;
    ConnectionSettings settings("connection_settings_server.txt");
    settings.Setup();
    Server* server = new Server(settings.GetPort(), settings.GetMaxDataSizeTransfer());
    int rc = pthread_create(&threads, NULL, StartOperation, (void*) server);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        pthread_exit(NULL);
    }
    CloseOperation(server);
    return 0;
}
