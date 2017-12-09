#ifndef REMOTE_PLAYER_RECIVER_
#define REMOTE_PLAYER_RECIVER_

#include "Player.h"
#include "ServerLinker.h"

class RemotePlayerReceiver : public Player {
public:
    RemotePlayerReceiver(Checker color, const BoardManager &board_, Graphic *graphic_, ServerLinker *serverLinker_);
    virtual ~RemotePlayerReceiver();
    virtual Point GetPointFromPlayer();
    //get point from player, with an error message
    virtual Point PointNotAvailable();

private:
    ServerLinker *serverLinker;
};
#endif //REMOTE_PLAYER_RECIVER_
