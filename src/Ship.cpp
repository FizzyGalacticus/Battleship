//Dustin Dodson & Bucky Frost
//Source file for Ship class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SHIP__CPP
#define __BATTLESHIP__SHIP__CPP

#include "Ship.h"

const vector<pair<int,int> > Ship::getCoordinates() const
{
	vector<pair<int,int> > temp;
	
	for( int i = 0; i < _activeCoordIndex.size(); i++)
		temp.push_back(_coordinates[i]);
	
	return temp;
}

const string & Ship::getNameOfShip() const
{
	return _nameOfShip;
}

const bool Ship::sustainDamage(const pair<int,int> damagedCoord)
{
	for(int i = 0; i < _activeCoordIndex.size(); i++)
		if(_coordinates[_activeCoordIndex[i]] == damagedCoord)
			_activeCoordIndex.erase(_activeCoordIndex.begin()+i);
	
	return _activeCoordIndex.size();
}

#endif