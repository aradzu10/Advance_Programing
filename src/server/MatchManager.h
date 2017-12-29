/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_MATCHMANAGER_H
#define REVERSI_MATCHMANAGER_H

#include "MatchHandler.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class MatchManager {

public:
    MatchManager();

    MatchManager(int max);

    ~MatchManager();

    void setMaxDataSizeToTransfer(int maxDataSizeToTransfer);

    vector<string> GetGamesList();

    void CreateNewMatch(string& name, int firstClient);

    void JoinMatch(string& name, int secondClient);

    void CloseMatch(string& name);

private:
    map<string, MatchHandler*> matches;
    int maxDataSizeToTransfer;

};


#endif //REVERSI_MATCHMANAGER_H
