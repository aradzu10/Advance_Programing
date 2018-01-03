/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <cstdio>
#include <cstring>
#include <sstream>
#include "RemotePlayerReceiver.h"

RemotePlayerReceiver::RemotePlayerReceiver(Checker color, Graphic *graphic_,
                     ServerLinker *serverLinker_) : Player(color, graphic_), serverLinker(serverLinker_) {
}

RemotePlayerReceiver::~RemotePlayerReceiver() {
}

Point RemotePlayerReceiver::GetPointFromPlayer() {
    char *point = serverLinker->ReadDataFromServer();
    if (!serverLinker->isConnnectedToServer()) {
        graphic->PrintMessage("Game disconnected...");
        return Point(-1, 0);
    }
    if (!strcmp(point, "NoMove")) {
        return Point(-2, 0);
    }
    int row, col;
    sscanf(point, "%d, %d", &row, &col);
    std::stringstream ss;
    ss << "Opponent choose: (" << row + 1 << ", " << col + 1 << ")";
    graphic->PrintMessage(ss.str());
    delete point;
    return Point(row, col);
}

Point RemotePlayerReceiver::PointNotAvailable() {
    return GetPointFromPlayer();
}

void RemotePlayerReceiver::NoMove() {
    char *message = serverLinker->ReadDataFromServer();
    delete message;
    Player::NoMove();
}

void RemotePlayerReceiver::GameEnded() {
    char *message = serverLinker->ReadDataFromServer();
    delete message;
}

bool RemotePlayerReceiver::PlayerInGame() {
    return serverLinker->isConnnectedToServer();
}
