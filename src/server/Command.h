/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H


class Command {

public:
    virtual ~Command() {}
    virtual void execute(int clientSocket) = 0;

};


#endif //REVERSI_COMMAND_H
