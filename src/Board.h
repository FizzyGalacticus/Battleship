//Dustin Dodson & Bucky Frost
//Source file for Board class header
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__H
#define __BATTLESHIP__BOARD__H

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Board
{
	public:
		Board();
		Board(const int);
		const bool isOccupied(const int, const int);
		void printBoard(ostream &);
	private:
		void initBoard();
		const string getEndString();
		const string getMidString();
		vector<vector<bool> > _board;
		const int _gridSize;
};

#endif