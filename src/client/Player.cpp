/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "Player.h"

Player::Player() {
}

Player::Player(Checker color, Graphic* graphic_) : player_color(color), graphic(graphic_) {
}

Player::~Player() {
}

Checker Player::GetColor() {
	return player_color;
}

Point Player::GetPointFromPlayer() {
	return Point(-1, -1);
}

Point Player::PointNotAvailable() {
	return Point(-1, -1);
}

void Player::MyTurn() {
	graphic->PrintTurnOf(player_color);
}

void Player::SuccessfulTurn(Point point) {
}

void Player::NoMove() {
	graphic->PrintMessage("No available moves");
}

void Player::GameEnded() {
}

bool Player::PlayerInGame() {
	return true;
}
