#include "RemotePlayerSender.h"
#include <sstream>

RemotePlayerSender::RemotePlayerSender(ServerLinker *serverLinker_, Player *localPlayer) :
        serverLinker(serverLinker_), localPlayer(localPlayer) {}

RemotePlayerSender::~RemotePlayerSender() {
    delete serverLinker;
}

Checker RemotePlayerSender::GetColor() {
    return localPlayer->GetColor();
}

Point RemotePlayerSender::GetPointFromPlayer() {
    Point point = localPlayer->GetPointFromPlayer();
    return point;
}

Point RemotePlayerSender::PointNotAvailable() {
    Point point = localPlayer->PointNotAvailable();
    return point;
}

void RemotePlayerSender::MyTurn() {
    localPlayer->MyTurn();
}

void RemotePlayerSender::SuccessfulTurn(Point point) {
    std::stringstream temp_str;
    temp_str<< point.getRow() << ", " << point.getCol();
    std::string str = temp_str.str();
    const char* parsedPoint = str.c_str();
    serverLinker->WriteDataToServer(parsedPoint, sizeof(parsedPoint));
}

void RemotePlayerSender::NoMove() {
    const char* noMove = "NoMove";
    serverLinker->WriteDataToServer(noMove, sizeof(noMove));
}

void RemotePlayerSender::GameEnded() {
    localPlayer->GameEnded();
}
