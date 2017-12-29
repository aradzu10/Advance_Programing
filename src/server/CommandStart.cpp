/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandStart.h"

CommandStart::CommandStart(MatchManager &matchManager) : matchManager(matchManager) {}

CommandStart::~Command() {}

void CommandStart::execute(int clientSocket, string &command) {
    matchManager.CreateNewMatch(command, clientSocket);
}
