//Dustin Dodson & Bucky Frost
//Source file for Board class header
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__H
#define __BATTLESHIP__BOARD__H

#include <vector>
using std::vector;

class Board
{
	public:
		Board();
		Board(const int);
		const bool isOccupied(const int, const int);
	private:
		void initBoard();
		vector<vector<bool> > _board;
		const int _gridSize;
};

#endif