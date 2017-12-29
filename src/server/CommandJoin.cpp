/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandJoin.h"

CommandJoin::CommandJoin(MatchManager &matchManager) : matchManager(matchManager) {}

CommandJoin::~Command() {}

void CommandJoin::execute(int clientSocket, string &command) {
    matchManager.JoinMatch(command, clientSocket);
}
