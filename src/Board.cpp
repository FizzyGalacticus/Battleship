//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"

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

#endif