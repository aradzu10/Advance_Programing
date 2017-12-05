/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "Player.h"

Player::Player(Checker color, const BoardManager& board_, Graphic* graphic_) : player_color(color), board(board_), graphic(graphic_) {
}

Player::~Player() {
}

Checker Player::GetColor() {
	return player_color;
}

Point Player::GetPointFromPlayer() {
	return Point(-1, -1);
}

Point Player::PointIsntAvialabe() {
	return Point(-1, -1);
}

void Player::MyTurn() {
	graphic->PrintTurnOf(player_color);
}

void Player::SuccessfulTurn() {
}

void Player::NoMove() {
	graphic->PrintMessage("No available moves");
}

void Player::GameEnded() {
}
