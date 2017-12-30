/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandClose.h"

CommandClose::CommandClose(MatchManager &matchManager) : matchManager(matchManager) {}

CommandClose::~CommandClose() {

}

int CommandClose::execute(int clientSocket, string &command) {
    return matchManager.CloseMatch(command);
}
