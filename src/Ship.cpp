//Dustin Dodson & Bucky Frost
//Source file for Ship class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SHIP__CPP
#define __BATTLESHIP__SHIP__CPP

#include "Ship.h"

const vector<pair<int,int> > Ship::getCoordinates()
{
	vector<pair<int,int> > temp;
	
	for( int i = 0; i < _activeCoordIndex.size(); i++)
		temp.push_back(_coordinates[i]);
	
	return temp;
}

const string & Ship::getNameOfShip()
{
	return _nameOfShip;
}

#endif