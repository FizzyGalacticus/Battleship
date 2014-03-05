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

const bool Board::isOccupied(const int x, const int y)
{
	return _board[x][y];
}

void Board::printBoard(ostream & out)
{	
	out << getEndString() << endl;
	
	for(int i = 0; i < _gridSize; i++)
	{
		for(int j = 0; j < _gridSize; j++)
		{
			out << "|." << (isOccupied(i,j)?'T':'F') << '.';
		}
		out << '|' << endl;
	}
	
	out << getEndString() << endl;
}

const string Board::getEndString()
{
	string temp;
	
	temp += '+';
	for(int i = 0; i < (_gridSize*4-1); i++) temp += '-';
	temp += '+';
	
	return temp;
}

#endif