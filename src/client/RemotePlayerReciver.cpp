#include "RemotePlayerReciver.h"

RemotePlayerReciver::RemotePlayerReciver(Checker color, const BoardManager &board_, Graphic *graphic_,
                     ServerLinker& serverLinker_) : Player(color, board_, graphic_), serverLinker(serverLinker_) {}


RemotePlayerReciver::~RemotePlayerReciver() {}

Point RemotePlayerReciver::GetPointFromPlayer() {
    char *point = serverLinker.ReadDataFromServer();

}
