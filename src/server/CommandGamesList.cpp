/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandGamesList.h"
#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <sstream>

using namespace std;

CommandGamesList::CommandGamesList(MatchManager &matchManager) : matchManager(matchManager) {}

CommandGamesList::~CommandGamesList() {

}

int CommandGamesList::execute(int clientSocket, string &command) {
    int check;
    vector<string> names = matchManager.GetGamesList();
    int size = names.size();
    check = send(clientSocket, &size, sizeof(size), 0);
    if (check <= 0) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        int len = names[i].size();
        check = send(clientSocket, &len, sizeof(len), 0);
        if (check <= 0) {
            return 0;
        }
        check = send(clientSocket, names[i].c_str(), names[i].size(), 0);
        if (check <= 0) {
            return 0;
        }
    }
    return 2;
}
