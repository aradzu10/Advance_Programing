/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandClose.h"

CommandClose::CommandClose(MatchManager &matchManager) : matchManager(matchManager) {}

CommandClose::~Command() {}

void CommandClose::execute(int clientSocket, string &command) {
    matchManager.CloseMatch(command);
}
