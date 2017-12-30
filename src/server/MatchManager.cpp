/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "MatchManager.h"

MatchManager::MatchManager() {
}

MatchManager::MatchManager(int max) : maxDataSizeToTransfer(max) {
}

void MatchManager::setMaxDataSizeToTransfer(int maxDataSizeToTransfer) {
    MatchManager::maxDataSizeToTransfer = maxDataSizeToTransfer;
}

MatchManager::~MatchManager() {
    CloseAll();
}

void MatchManager::CloseAll() {
    for (map<string, MatchHandler *>::iterator it = matches.begin(); it != matches.end(); ++it) {
        CloseMatch(it->first);
    }
}

vector<string> MatchManager::GetGamesList() {
    vector<string> matchesName;
    for (map<string, MatchHandler *>::iterator it = matches.begin(); it != matches.end(); ++it) {
        if (!it->second->isGameStarted()) {
            matchesName.push_back(it->first);
        }
    }
    return matchesName;
}

int MatchManager::CreateNewMatch(string &name, int firstClient) {
    if (matches.find(name) == matches.end()) {
        MatchHandler *matchHandler = new MatchHandler(maxDataSizeToTransfer);
        matchHandler->setClientSocket1(firstClient);
        matches[name] = matchHandler;
        return 0;
    }
    return 1;
}

int MatchManager::JoinMatch(string &name, int secondClient) {
    if (matches.find(name) == matches.end()) {
        return 1;
    }
    matches[name]->setClientSocket2(secondClient);
    matches[name]->Start();
    CloseMatch(name);
    return 0;
}

int MatchManager::CloseMatch(const string &name) {
    if (matches.find(name) == matches.end()) {
        return 1;
    }
    matches[name]->Close();
    matches.erase(name);
    return 0;
}
