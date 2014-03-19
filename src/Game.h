//Dustin Dodson & Bucky Frost
//Source file for Game class header
//CS372 Project 1

#ifndef __BATTLESHIP__GAME__H
#define __BATTLESHIP__GAME__H

#include "Player.h"
#include "menues.cpp"
#include "Sound.h"

#include <vector>
using std::vector;

class Game
{
	public:
		void initGame();
		void preGame();
	private:
		vector<Player *> _players;
		static vector<string> _backgroundMusicFileNames;
};

#endif