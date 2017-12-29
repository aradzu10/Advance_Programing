/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMANDJOIN_H
#define REVERSI_COMMANDJOIN_H


#include "MatchManager.h"
#include "Command.h"

class CommandJoin : public Command {

public:
    CommandJoin(MatchManager &matchManager);
    virtual ~Command();
    virtual void execute(int clientSocket, string& command);

private:
    MatchManager& matchManager;

};


#endif //REVERSI_COMMANDJOIN_H
