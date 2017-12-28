/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "CommandManager.h"

CommandManager::CommandManager() {}

void CommandManager::DoCommand(string &command, int clientSocket) {
    Command *c = commands[command];

}
