/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandJoin.h"

CommandJoin::CommandJoin(MatchManager &matchManager) : matchManager(matchManager) {}

CommandJoin::~CommandJoin() {

}

int CommandJoin::execute(int clientSocket, string &command) {
    return matchManager.JoinMatch(command, clientSocket);
}
