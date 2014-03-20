//Dustin Dodson & Bucky Frost
//Source file for Player class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__CPP
#define __BATTLESHIP__PLAYER__CPP

#include "Player.h"
#include <iostream>
using std::endl;
#include <string>
using std::string;

Player::Player(ostream & streamToOutputTo, const string & givenName): _name(givenName), _outputStream(streamToOutputTo), _playerBoard(_outputStream) {}

void Player::printBoard(const bool & showShips)
{
	_playerBoard.printBoard(showShips);
}

const string & Player::getPlayerName() const
{return _name;}

void Player::attackOpponent(Player * opponent)
{
	_outputStream << _name << "'s turn" << endl;
	opponent->_playerBoard.attackBoardCoordinate();
}

const bool Player::isStillActive()
{
	return _playerBoard.shipsStillActive();
}

#endif
