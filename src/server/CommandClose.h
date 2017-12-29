/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMANDCLOSE_H
#define REVERSI_COMMANDCLOSE_H


#include "MatchManager.h"
#include "Command.h"

class CommandClose : public Command {

public:
    CommandClose(MatchManager &matchManager);
    virtual ~Command();
    virtual void execute(int clientSocket, string& command);

private:
    MatchManager& matchManager;
};


#endif //REVERSI_COMMANDCLOSE_H
