/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include <cstdio>
#include <cstring>
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

int CommandManager::DoCommand(char* userInput, int clientSocket) {
    char command[strlen(userInput)], input[strlen(userInput)];
    sscanf(userInput, "%s %s", command, input); // check - gamelist
    string sCommand(command);
    string sInput(input);
    Command *c = commands[sCommand];
    return c->execute(clientSocket, sInput);
}
