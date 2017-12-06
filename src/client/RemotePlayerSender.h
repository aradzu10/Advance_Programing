#ifndef REMOTE_PLAYER_SENDER_
#define REMOTE_PLAYER_SENDER_

#include "Player.h"
#include "ServerLinker.h"

class RemotePlayerSender : public Player {
public:
    RemotePlayerSender(Checker color, const BoardManager &board_, Graphic *graphic_, ServerLinker& serverLinker_, Player localPlayer);
    virtual ~RemotePlayerSender();

    virtual Point GetPointFromPlayer();
    //get point from player, with an error message
    virtual Point PointNotAvailable();
    virtual void SuccessfulTurn(Point point);
    virtual void NoMove();

private:
    ServerLinker& serverLinker;
    Player& localPlayer;
};

#endif //REMOTE_PLAYER_SENDER_
