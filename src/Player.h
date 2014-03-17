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
		static void assignOpponentBoards();
	private:
		Player();
		Board _playerBoard;
		const Board * _opponentBoard;
		int selfPositionInPlayers; 		//Maybe a better name?
		const string _name;
};

#endif