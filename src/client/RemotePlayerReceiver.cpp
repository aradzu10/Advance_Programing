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
    char *point = serverLinker->ReadDataFromServer();
    delete point;
    Player::NoMove();
}
