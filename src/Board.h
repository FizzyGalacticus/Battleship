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

typedef pair<int, int> Coordinate;

class Board
{
	public:
		Board();
		Board(const int);
		const bool isOccupied(const Coordinate &);
		void printBoard(ostream &, const bool);
		void attackBoardCoordinate();
		const bool shipsStillActive() const;
	private:
		void initBoard();
		Coordinate parseUserInput(const string &);
		const string attackCoordinatePrompt();
		void setCellContents(const int, const int, const char);
		
		//***		Private Computational Functions			***//
		vector<Coordinate> computeLeftAndUpCoordinates(const Coordinate &, const char &, const int &);
		vector<Coordinate> computeRightAndDownCoordinates(const Coordinate &, const char &, const int &);
		
		//***		Private Ship Manipulation Functions		***//
		void initShips();
		const string initialShipCoordinatePrompt(const string &, const int &);
		const vector<string> parsePossibleShipDirections(const vector<vector<Coordinate > >);
		const char shipDirectionalPrompt(const vector<vector<Coordinate > > &);
		void assignShipCoordinatesOnBoard(const Ship &);
		const int findShipWithCoordinates(const Coordinate) const;
		const vector<vector<Coordinate> > getPossibleShipDirection(const Coordinate &, const int &);
		
		//***		Private Board Printing Functions		***//
		const char getCellContents(const int, const int);
		const string getEndString() const;
		const string getMidString() const;
		
		//***			Private Member Variables			***//
		vector<vector<char> > _board;
		const int _gridSize;
		vector<Ship> _shipsInPlay;
};

#endif
