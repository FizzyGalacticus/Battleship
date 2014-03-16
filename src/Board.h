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

#include <utility>
using std::pair;

#include "Ship.h"

class Board
{
	public:
		Board();
		Board(const int);
		const bool isOccupied(const int, const int);
		void printBoard(ostream &);
	private:
		void initBoard();
		void initShips();
		pair<int,int> parseUserInput(const string &);
		const vector<vector<pair<int, int> > > getPossibleShipDirection(const pair<int,int> &, const int &);
		const char getCellContents(const int, const int);
		void assignShipCoordinatesOnBoard(const Ship &);
		const string getEndString();
		const string getMidString();
		vector<vector<char> > _board;
		const int _gridSize;
		vector<Ship> _ships;
};

#endif
