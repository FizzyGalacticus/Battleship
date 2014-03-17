//Dustin Dodson & Bucky Frost
//Source file for Player class header
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__H
#define __BATTLESHIP__PLAYER__H

#include "Board.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

class Player
{
	public:
		Player(const string &);
		static vector<const Player *> _existingPlayers;
		static int _activePlayer;
	private:
		Player();
		Board _playerBoard;
		int selfPositionInPlayers; 		//Maybe a better name?
		const string _name;
};

#endif