#include <cstdio>
#include <cstring>
#include "RemotePlayerReceiver.h"

RemotePlayerReceiver::RemotePlayerReceiver(Checker color, const BoardManager &board_, Graphic *graphic_,
                     ServerLinker *serverLinker_) : Player(color, board_, graphic_), serverLinker(serverLinker_) {}


RemotePlayerReceiver::~RemotePlayerReceiver() {}

Point RemotePlayerReceiver::GetPointFromPlayer() {
    char *point = serverLinker->ReadDataFromServer();
    if (!strcmp(point, "NoMove")) {
        return Point(-2, 0);
    }
    int row, col;
    sscanf(point, "%d, %d", &row, &col);
    delete point;
    return Point(row, col);
}

Point RemotePlayerReceiver::PointNotAvailable() {
    return GetPointFromPlayer();
}
