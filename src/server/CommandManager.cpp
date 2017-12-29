/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include <cstdio>
#include "CommandManager.h"
#include "CommandClose.h"
#include "CommandStart.h"
#include "CommandJoin.h"
#include "CommandGamesList.h"

CommandManager::CommandManager() {
}

CommandManager::CommandManager(MatchManager &matchManager) {
    setMatchManager(matchManager);
}

void CommandManager::setMatchManager(MatchManager &matchManager) {
    commands["start"] = new CommandStart(matchManager);
    commands["join"] = new CommandJoin(matchManager);
    commands["list_games"] = new CommandGamesList(matchManager);
    commands["close"] = new CommandClose(matchManager);
}

void CommandManager::DoCommand(char* userInput, int clientSocket) {
    string command, input;
    sscanf(userInput, "%s %s", command, input); // check - gamelist
    Command *c = commands[command];
    c->execute(clientSocket, input);
}
