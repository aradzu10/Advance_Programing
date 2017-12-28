/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#include "MatchManager.h"

MatchManager::MatchManager(int max) : maxDataSizeToTransfer(max) {
}

MatchManager::~MatchManager() {
    for(map<string, MatchHandler*>::iterator it = matches.begin(); it != matches.end(); ++it) {
        it->second->Close();
    }
}

vector<string> MatchManager::GetGamesList() {
    vector<string> matchesName;
    for(map<string, MatchHandler*>::iterator it = matches.begin(); it != matches.end(); ++it) {
        matchesName.push_back(it->first);
    }
    return matchesName;
}

void MatchManager::CreateNewMatch(string &name, int firstClient) {
    MatchHandler *matchHandler = new MatchHandler(maxDataSizeToTransfer);
    matchHandler->setClientSocket1(firstClient);
    matches[name] = matchHandler;
}

void MatchManager::JoinMatch(string &name, int secondClient) {
    matches[name]->setClientSocket2(secondClient);
    //add - thread here
    matches[name]->Start();
    CloseMatch(name);
}

void MatchManager::CloseMatch(string &name) {
    matches[name]->Close();
    matches.erase(name);
}
