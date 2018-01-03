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
    // close all matches
    void CloseAll();
    // return game list
    vector<string> GetGamesList();
    // create new match, and set first client
    int CreateNewMatch(string& name, int firstClient);
    // set second client in match and start match
    int JoinMatch(string& name, int secondClient);
    // close match - close clients and earse game from list
    int CloseMatch(const string& name);

private:
    map<string, MatchHandler*> matches;
    int maxDataSizeToTransfer;

};


#endif //REVERSI_MATCHMANAGER_H
