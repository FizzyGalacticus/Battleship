//Dustin Dodson & Bucky Frost
//Source file for Player class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__CPP
#define __BATTLESHIP__PLAYER__CPP

#include "Player.h"

vector<const Player *> Player::_existingPlayers;

Player::Player(const string & givenName): _name(givenName), _playerBoard()
{
	_existingPlayers.push_back(this);
	selfPositionInPlayers = (_existingPlayers.size()-1);
}

void Player::assignOpponentBoards()
{
	
}

#endif