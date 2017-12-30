/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMANDSTART_H
#define REVERSI_COMMANDSTART_H

#include "MatchManager.h"
#include "Command.h"
#include <iostream>
using namespace std;

class CommandStart : public Command {

public:
    CommandStart(MatchManager &matchManager);
    virtual ~CommandStart();
    virtual int execute(int clientSocket, string& command);

private:
    MatchManager& matchManager;

};


#endif //REVERSI_COMMANDSTART_H
