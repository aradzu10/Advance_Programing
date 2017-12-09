/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef REMOTE_PLAYER_SENDER_
#define REMOTE_PLAYER_SENDER_

#include "Player.h"
#include "ServerLinker.h"

//remote player, using for player. talk to server using server linker and send data
class RemotePlayerSender : public Player {
public:
    RemotePlayerSender(ServerLinker *serverLinker_, Player *localPlayer);
    virtual ~RemotePlayerSender();
    //get color
    virtual Checker GetColor();
    //get point from player
    virtual Point GetPointFromPlayer();
    //get point from player with an error message
    virtual Point PointNotAvailable();
    //print my turn message
    virtual void MyTurn();
    //alart success turn
    virtual void SuccessfulTurn(Point point);
    //alart no available move
    virtual void NoMove();
    //alart game ended
    virtual void GameEnded();

private:
    //members
    ServerLinker *serverLinker;
    Player *localPlayer;
};

#endif //REMOTE_PLAYER_SENDER_
