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

void CommandGamesList::execute(int clientSocket, string command) {
    int check;
    vector<string> names = matchManager.GetGamesList();
    stringstream size;
    size <<  names.size();
    check = send(clientSocket, size.str().c_str(), size.str().size(), 0);
    if (check <= 0) {

        return;
    }
    for (int i=0; i < names.size(); i++) {
        check = send(clientSocket, names[i].c_str(), names[i].size(), 0);
        if (check <= 0) {

            return;
        }
    }
}
