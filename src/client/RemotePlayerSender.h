#ifndef REMOTE_PLAYER_SENDER_
#define REMOTE_PLAYER_SENDER_

#include "Player.h"
#include "ServerLinker.h"

class RemotePlayerSender : public Player {
public:
    RemotePlayerSender(ServerLinker *serverLinker_, Player *localPlayer);
    virtual ~RemotePlayerSender();

    virtual Checker GetColor();
    //get point from player - return false point, childs will change it
    virtual Point GetPointFromPlayer();
    virtual Point PointNotAvailable();
    virtual void MyTurn();
    virtual void SuccessfulTurn(Point point);
    virtual void NoMove();
    virtual void GameEnded();

private:
    ServerLinker *serverLinker;
    Player *localPlayer;
};

#endif //REMOTE_PLAYER_SENDER_
