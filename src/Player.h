//Dustin Dodson & Bucky Frost
//Source file for Player class header
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__H
#define __BATTLESHIP__PLAYER__H

#include "Board.h"

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Player
{
	public:
		Player(ostream &, const string &);
		void printBoard(const bool &);
		const string & getPlayerName() const;
		void attackOpponent(Player *);
		const bool isStillActive();
	private:
		Player();
		Board _playerBoard;
		string _name;
		ostream & _outputStream;
};

#endif