#ifndef REMOTE_PLAYER_RECIVER_
#define REMOTE_PLAYER_RECIVER_

#include "Player.h"
#include "ServerLinker.h"

class RemotePlayerReciver : public Player {
public:
    RemotePlayerReciver(Checker color, const BoardManager &board_, Graphic *graphic_, ServerLinker& serverLinker_);
    virtual ~RemotePlayerReciver();
    virtual Point GetPointFromPlayer();
    //get point from player, with an error message
    virtual Point PointNotAvailable();

private:
    ServerLinker& serverLinker;
};
#endif //REMOTE_PLAYER_RECIVER_
