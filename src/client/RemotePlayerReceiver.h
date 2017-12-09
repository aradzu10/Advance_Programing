/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef REMOTE_PLAYER_RECIVER_
#define REMOTE_PLAYER_RECIVER_

#include "Player.h"
#include "ServerLinker.h"

//remote player, using for opponent. talk to server using server linker and read data
class RemotePlayerReceiver : public Player {
public:
    RemotePlayerReceiver(Checker color, Graphic *graphic_, ServerLinker *serverLinker_);
    virtual ~RemotePlayerReceiver();
    //get point from player
    virtual Point GetPointFromPlayer();
    //get point from player, with an error message
    virtual Point PointNotAvailable();
    //receive no move message
    virtual void NoMove();
    //receive end game message
    virtual void GameEnded();

private:
    //members
    ServerLinker *serverLinker;
};
#endif //REMOTE_PLAYER_RECIVER_
