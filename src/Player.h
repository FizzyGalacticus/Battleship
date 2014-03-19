//Dustin Dodson & Bucky Frost
//Source file for Player class header
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__H
#define __BATTLESHIP__PLAYER__H

#include "Board.h"

#include <string>
using std::string;

class Player
{
	public:
		Player(const string &);
		void printBoard(const bool &);
		const string & getPlayerName() const;
		void attackOpponent(Player *);
		const bool isStillActive();
	private:
		Player();
		Board _playerBoard;
		string _name;
};

#endif