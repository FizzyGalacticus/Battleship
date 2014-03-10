//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"
#include <iostream>
using std::endl;


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
	
	while(isNotValidInput)
	{
		
	}
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