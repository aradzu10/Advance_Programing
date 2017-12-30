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

    void CloseAll();

    void setMaxDataSizeToTransfer(int maxDataSizeToTransfer);

    vector<string> GetGamesList();

    int CreateNewMatch(string& name, int firstClient);

    int JoinMatch(string& name, int secondClient);

    int CloseMatch(const string& name);

private:
    map<string, MatchHandler*> matches;
    int maxDataSizeToTransfer;

};


#endif //REVERSI_MATCHMANAGER_H
