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
		static vector<Player *> _existingPlayers;
		static int _activePlayer;
		void printPublicBoard();
		const string & getPlayerName() const;
		void attackOpponent();
		const bool & isStillActive();
	private:
		Player();
		Board _playerBoard;
		int selfPositionInPlayers; 		//Maybe a better name?
		string _name;
};

#endif