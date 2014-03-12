//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "osFunctions.cpp"


Board::Board() : _gridSize(9)
{
	initBoard();
}

Board::Board(const int size) : _gridSize(size)
{
	initBoard();
}

void Board::initBoard()
{
	vector<bool> temp(_gridSize, false);
	for(int i = 0; i < _gridSize; i++)
	{
		_board.push_back(temp);
	}
}

void Board::initShips()
{
	for(map<string,int>::const_iterator itr = Ship::_shipTypes.begin(); itr != Ship::_shipTypes.end(); itr++)
		_ships.push_back(Ship(itr->first));
	
	bool isNotValidInput = true;
	string input;
	pair<int,int> inputCoordinate;
	
	//Go through each ship
	for(int i = 0; i < _ships.size(); i++)
	{
		vector<pair<int,int> > totalInputCoordinates;
		const int & shipHitpoints = _ships[i].getNumberOfHitPoints();
		const string & shipName = _ships[i].getNameOfShip();
		
		//Get proper input of coordinates
		while(isNotValidInput)
		{
			printBoard(cout);
			
			cout << "Please type desired coordinates for front of " << shipName
				<< endl << '(' << shipHitpoints << " total spaces neeed) " << "(example: 'I4'): ";
			getline(cin, input);
			
			inputCoordinate = parseUserInput(input);
			clearScreen();
			
			//Set proper coordinates to ship
			if(inputCoordinate.first > 0 && inputCoordinate.second > 0)
			{
				isNotValidInput = false;
				totalInputCoordinates.push_back(inputCoordinate);
				const vector<vector<pair<int, int> > > possibleShipDirections = getPossibleShipDirection(inputCoordinate, shipHitpoints);
				char directionInput = 0;
				
				//Get directional coordinates of ship
				//Add to totalInputCoordinates
				//Set _ships[i] coordinates to totalInputCoordinates
			}
		}
	}
}

//TODO
pair<int,int> Board::parseUserInput(const string & input)
{
	return pair<int,int>(-1,-1);
}

const vector<vector<pair<int, int> > > Board::getPossibleShipDirection(const pair<int,int> & userGivenCoords, const int & shipHitpoints)
{
	vector<vector<pair<int, int> > > possibleDirections;
	const int xCoord = userGivenCoords.first, yCoord = userGivenCoords.second, spaceNeeded = (shipHitpoints - 1);
	
	possibleDirections.push_back(getUpAndLeftCoords(xCoord, spaceNeeded, 'U'));
	possibleDirections.push_back(getDownAndRightCoords(xCoord, spaceNeeded, 'D'));
	possibleDirections.push_back(getUpAndLeftCoords(yCoord, spaceNeeded, 'L'));
	possibleDirections.push_back(getDownAndRightCoords(yCoord, spaceNeeded, 'R'));
	
	return possibleDirections;	
}

//MAYBE WE CAN REFACTOR THIS?!
const vector<pair<int, int> > Board::getDownAndRightCoords(const int baseCoord, const int spaceNeeded, const char direction)
{
	//Vectors that are to hold coordinates, one for coordinates that we add as we check them,
	//the other for all coordinates once we verify that the Ship will fit in that area.
	vector<pair<int, int> > possibleCoords, coordsChecked;
	
	if((baseCoord + spaceNeeded ) <= (_gridSize - 1))
	{
		//Go through all coordinates that need to be checked
		for(int i = baseCoord; i <= (baseCoord + spaceNeeded); i++)
		{
			//Add this coordinate to the checked coord vector depending on direction
			coordsChecked.push_back((direction == 'D')?pair<int, int>(baseCoord,i):pair<int, int>(i,baseCoord));
			
			//Break and return empty vector if any of the spaces contain a ship
			if((direction == 'U')?_board[baseCoord][i]:_board[i][baseCoord]) break;
			if(i == baseCoord && !((direction == 'D')?_board[baseCoord][i]:_board[i][baseCoord])) possibleCoords = coordsChecked;
		}
	}
	
	return possibleCoords;
}

//MAYBE WE CAN REFACTOR THIS?!
const vector<pair<int, int> > Board::getUpAndLeftCoords(const int baseCoord, const int spaceNeeded, const char direction)
{
	//Vectors that are to hold coordinates, one for coordinates that we add as we check them,
	//the other for all coordinates once we verify that the Ship will fit in that area.
	vector<pair<int, int> > possibleCoords, coordsChecked;
	
	if((baseCoord - spaceNeeded ) >= 0)
	{
		//Go through all coordinates that need to be checked
		for(int i = (baseCoord - spaceNeeded); i <= baseCoord; i++)
		{
			//Add this coordinate to the checked coord vector depending on direction
			coordsChecked.push_back((direction == 'U')?pair<int, int>(baseCoord,i):pair<int, int>(i,baseCoord));
			
			//Break and return empty vector if any of the spaces contain a ship
			if((direction == 'U')?_board[baseCoord][i]:_board[i][baseCoord]) break;
			if(i == baseCoord && !((direction == 'U')?_board[baseCoord][i]:_board[i][baseCoord])) possibleCoords = coordsChecked;
		}
	}
	
	return possibleCoords;
}

const bool Board::isOccupied(const int x, const int y)
{
	return _board[x][y];
}

void Board::printBoard(ostream & out)
{	
	//print row index
	const char rowHeaders[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	
	for(int i = 0; i < _gridSize; i++) out  << "   " << rowHeaders[i];
	out << endl;
	
	out << ' ' << getEndString() << endl;
	out << getMidString() << endl;
	
	for(int i = 0; i < _gridSize; i++)
	{
		out << i;
		for(int j = 0; j < _gridSize; j++)
		{
			out << "| " << (isOccupied(i,j)?'T':'F') << ' ';
		}
		out << '|' << endl;
		out << getMidString() << endl;
	}
	
	out << ' ' << getEndString() << endl;
}

const string Board::getEndString()
{
	string temp;
	
	temp += '+';
	for(int i = 0; i < (_gridSize*4-1); i++) temp += '-';
	temp += '+';
	
	return temp;
}

const string Board::getMidString()
{
	string temp;
	
	for(int i = 0; i < _gridSize; i++) temp += " | -";
	temp += " |";
	
	return temp;
}

#endif