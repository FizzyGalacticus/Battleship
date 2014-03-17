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
		typedef pair<int, int> Coordinate;
		Board();
		Board(const int);
		const bool isOccupied(const Coordinate &);
		void printBoard(ostream &);
		void attackBoardCoordinate();
	private:
		void initBoard();
		void initShips();
		Coordinate parseUserInput(const string &);
		const vector<vector<Coordinate> > getPossibleShipDirection(const Coordinate &, const int &);
		const char getCellContents(const int, const int);
		void setCellContents(const int, const int, const char);
		void assignShipCoordinatesOnBoard(const Ship &);
		const int findShipWithCoordinates(const Coordinate) const;
		vector<Coordinate> getLeftAndUpCoordinates(const Coordinate &, const char &, const int &);
		vector<Coordinate> getRightAndDownCoordinates(const Coordinate &, const char &, const int &);
		const string initialShipCoordinatePrompt(const string &, const int &);
		const vector<string> parsePossibleShipDirections(const vector<vector<Coordinate > >);
		const char shipDirectionalPrompt(const vector<vector<Coordinate > > &);
		const string attackCoordinatePrompt();
		const string getEndString();
		const string getMidString();
		vector<vector<char> > _board;
		const int _gridSize;
		vector<Ship> _ships;
};

class PlayerBoard : public Board
{
	public:
		
	private:
};

class OpponentBoard : public Board
{
	public:
		
	private:
		
};

#endif
