/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H

#include <iostream>
using namespace std;

class Command {

public:
    virtual ~Command();
    virtual void execute(int clientSocket, string& command) = 0;

};


#endif //REVERSI_COMMAND_H
