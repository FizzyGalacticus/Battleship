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
		
		//Get proper input of coordinates
		while(isNotValidInput)
		{
			printBoard(cout);
			
			cout << "Please type desired coordinates for front of ship (example: 'I4'): ";
			getline(cin, input);
			
			inputCoordinate = parseUserInput(input);
			clearScreen();
			
			//Set proper coordinates to ship
			if(inputCoordinate.first > 0 && inputCoordinate.second > 0)
			{
				isNotValidInput = false;
				totalInputCoordinates.push_back(inputCoordinate);
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

//TODO
const string Board::getPossibleShipDirection(const pair<int,int> & userGivenCoords, const int & shipHitpoints)
{
	string possibleDirections;
	const int xCoord = userGivenCoords.first, yCoord = userGivenCoords.second, spaceNeeded = (shipHitpoints - 1);
	
	//Check right direction
	if((xCoord + spaceNeeded ) <= (_gridSize - 1))
		for(int i = xCoord; i < (xCoord + spaceNeeded); i++)
		{
			if(_board[i][yCoord]) break;
			if(i == (xCoord + spaceNeeded) && !(_board[i][yCoord])) possibleDirections += "R";
		}
	
	//Check down direction
	if((yCoord + spaceNeeded ) <= (_gridSize - 1))
		for(int i = yCoord; i < (yCoord + spaceNeeded); i++)
		{
			if(_board[xCoord][i]) break;
			if(i == (yCoord + spaceNeeded) && !(_board[xCoord][i])) possibleDirections += "D";
		}
	
	//Check left direction
	if((xCoord - spaceNeeded ) >= 0)
		for(int i = xCoord; i >= (xCoord - spaceNeeded); i--)
		{
			if(_board[i][yCoord]) break;
			if(i == (xCoord - spaceNeeded) && !(_board[i][yCoord])) possibleDirections += "L";
		}
	
	//Check up direction
	if((yCoord - spaceNeeded ) >= 0)
		for(int i = yCoord; i >= (yCoord - spaceNeeded); i--)
		{
			if(_board[xCoord][i]) break;
			if(i == (yCoord - spaceNeeded) && !(_board[xCoord][i])) possibleDirections += "U";
		}
	
	return possibleDirections;	
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