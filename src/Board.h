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
		//Pre: None.
		//Post: Sets private member variables. Does call for user input.
		Board();
		
		//Pre: Must be passed a valid integer > 0 < 26 to be used to grid size.
		//Post: Sets private member variables. Does call for user input. If number is less than 5, default grid size is set to 5.
		Board(const int);
		
		//Pre: Must be passed a valid std::pair<int,int> as coordinates.
		//Post: Will return a boolean indicating whether or not spot on board is filled with a Ship object.
		const bool isOccupied(const Coordinate &) const;
		
		//Pre: Must be passed a valid std::ostream objects and boolean indicating whether or not to show the ships on the board.
		//Post: Will write formatted board to std::ostream.
		void printBoard(ostream &, const bool);
		
		//Pre: Must be passed a valid output stream.
		//Post: Will attempt to attack a ship at user given coordinates.
		void attackBoardCoordinate(ostream &);
		
		//Pre: None.
		//Post: Will return true if there is still at least one active Ship object on board.
		const bool shipsStillActive() const;
	private:
		//Pre: None.
		//Post: Initializes a blank Board object.
		void initBoard();
		
		//Pre: Must be passed a std::string object of size >= 2.
		//Post: Will return a valid std::pair<int,int> object with corresponding coordinates.
		Coordinate parseUserInput(const string &);
		
		//Pre: None.
		//Post: Returns user input as std::string object.
		const string attackCoordinatePrompt();
		
		//Pre: Must be passed a valid Coordinate object and a character.
		//Post: Will set cell of Coordinate indices to given character.
		void setCellContents(Coordinate, const char);
		
		//***		Private Computational Functions			***//
		//Pre: Must be passed a valid Coordinate (starting position), character (direction), and integer (Ship's hitpoints - 1) object.
		//Post: Will place Ship object within valid coordinates on Board.
		vector<Coordinate> computeLeftOrUpCoordinates(const Coordinate &, const char &, const int &);
		
		//Pre: Must be passed a valid Coordinate (starting position), character (direction), and integer (Ship's hitpoints - 1) object.
		//Post: Will place Ship object within valid coordinates on Board.
		vector<Coordinate> computeRightOrDownCoordinates(const Coordinate &, const char &, const int &);
		
		//***		Private Ship Manipulation Functions		***//
		//Pre: None.
		//Post: Will initialize Ship objects and place into valid coordinates on board.
		void initShips();
		
		//Pre: Must be passed valid std::string and integer objects.
		//Post: Will return a std::string object holding user specified coordinates.
		const string initialShipCoordinatePrompt(const string &, const int &);
		
		//Pre: Must be passed a valid vector<vector<Coordinate > > object holding the possible coordinates for each direction of a Ship object.
		//Post: Returns a std::vector<std::string> objects holding all possible orientations for the Ship object.
		const vector<string> parsePossibleShipDirections(const vector<vector<Coordinate > >);
		
		//Pre: Must be passed a valid vector<vector<Coordinate > > object holding the possible coordinates for each direction of a Ship object.
		//Post: Will return the first character specified by the user.
		const char shipOrientationPrompt(const vector<vector<Coordinate > > &);
		
		//Pre: Must be passed a valid Ship object with initialized coordinates.
		//Post: Will write Ship object representation to board.
		void assignShipCoordinatesOnBoard(const Ship &);
		
		//Pre: Must be passed a valid Coordinate object.
		//Post: Will return the _shipsInPlay index to the Ship with those coordinates.
		const int findShipWithCoordinates(const Coordinate) const;
		
		//Pre: Must be passed valid Coordinate and integer object.
		//Post: Will return a valid vector<vector<Coordinate > > object holding the possible coordinates for each direction of a Ship object.
		const vector<vector<Coordinate> > getPossibleShipDirection(const Coordinate &, const int &);
		
		//***		Private Board Printing Functions		***//
		//Pre: Must be passed valid Coordinate object.
		//Post: Will return the board character at that coordinate.
		const char getCellContents(const Coordinate &) const;
		
		//Pre: None
		//Post: Returns a pretty formatted std::string object for printing board to screen.
		const string getEndString() const;
		
		//Pre: None
		//Post: Returns a pretty formatted std::string object for printing board to screen.
		const string getMidString() const;
		
		//***			Private Member Variables			***//
		vector<vector<char> > _board;
		const int _gridSize;
		vector<Ship> _shipsInPlay;
};

#endif
