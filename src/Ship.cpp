//Dustin Dodson & Bucky Frost
//Source file for Ship class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SHIP__CPP
#define __BATTLESHIP__SHIP__CPP

#include "Ship.h"

const map<string,int> Ship::_shipTypes = createShipTypes();

const map<string,int> Ship::createShipTypes()
{
	map<string,int> ourMap;
	
	ourMap["Aircraft Carrier"] = 5;
	ourMap["Battleship"] = 4;
	ourMap["Submarine"] = 3;
	ourMap["Cruiser"] = 3;
	ourMap["Destroyer"] = 2;
	
	return ourMap;
}

Ship::Ship(string shipName)
{
	map<string,int>::const_iterator itr = _shipTypes.find(shipName);
	
	if(itr != _shipTypes.end())
	{
		_nameOfShip = itr->first;
		_hitPoints = itr->second;
	}
}

const int & Ship::getNumberOfHitPoints() {return _hitPoints;}

const vector<pair<int,int> > Ship::getCoordinates() const
{
	vector<pair<int,int> > temp;
	
	for( int i = 0; i < _activeCoordIndex.size(); i++)
		temp.push_back(_coordinates[i]);
	
	return temp;
}

void Ship::setCoordinates(vector<pair<int,int> > shipCoordinates)
{
	_coordinates = shipCoordinates;
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