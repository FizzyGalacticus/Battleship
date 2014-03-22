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
		void mainGameLoop();
		const bool allPlayersAreStillAlive();
		void setBackgroundMusicFiles(vector<string> &);
	private:
		vector<string> _backgroundMusicFileNames;
		vector<Player *> _players;
		static int _activePlayerIndex;
		void printPlayerBoards();
		const int indexToWinningPlayer() const;
		void printWinnerMessage(const int) const;
};

#endif
