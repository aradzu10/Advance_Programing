#include <cstdio>
#include <cstring>
#include "RemotePlayerReciver.h"

RemotePlayerReciver::RemotePlayerReciver(Checker color, const BoardManager &board_, Graphic *graphic_,
                     ServerLinker& serverLinker_) : Player(color, board_, graphic_), serverLinker(serverLinker_) {}


RemotePlayerReciver::~RemotePlayerReciver() {}

Point RemotePlayerReciver::GetPointFromPlayer() {
    char *point = serverLinker.ReadDataFromServer();
    if (strcmp(point, "NoMove")) {
        return Point(-2, 0);
    }
    int row, col;
    sscanf(point, "%d, %d", &row, &col);
    return Point(row, col);
}

Point RemotePlayerReciver::PointNotAvailable() {
    return GetPointFromPlayer();
}
