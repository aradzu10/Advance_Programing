/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMANDMANAGER_H
#define REVERSI_COMMANDMANAGER_H

#include "Command.h"
#include "MatchManager.h"
#include <iostream>
#include <map>
using namespace std;

class CommandManager {
public:
    CommandManager();
    CommandManager(MatchManager &matchManager);

    virtual ~CommandManager();
    // set match manager for commands
    void setMatchManager(MatchManager &matchManager);
    // do certain command
    int DoCommand(char* userInput, int clientSocket);

private:
    map<string, Command*> commands;

};


#endif //REVERSI_COMMANDMANAGER_H
