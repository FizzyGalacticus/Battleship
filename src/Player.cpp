//Dustin Dodson & Bucky Frost
//Source file for Player class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__CPP
#define __BATTLESHIP__PLAYER__CPP

#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

Player::Player(const string & givenName): _name(givenName), _playerBoard()
{
	
}

void Player::printBoard(const bool & showShips)
{
	_playerBoard.printBoard(cout, showShips);
}

const string & Player::getPlayerName() const
{return _name;}

void Player::attackOpponent(Player * opponent)
{
	cout << _name << "'s turn" << endl;
	opponent->_playerBoard.attackBoardCoordinate(cout);
}

const bool Player::isStillActive()
{
	return _playerBoard.shipsStillActive();
}

#endif
