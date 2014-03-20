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

const int & Ship::getNumberOfHitPoints() const
{
	return _hitPoints;
}

const vector<Coordinate > Ship::getCoordinates() const
{
	return _validShipCoordinates;
}

void Ship::setCoordinates(vector<Coordinate > shipCoordinates)
{
	_validShipCoordinates = shipCoordinates;
}

const string & Ship::getNameOfShip() const
{
	return _nameOfShip;
}

void Ship::sustainDamage(const Coordinate damagedCoord)
{
	for(int i = 0; i < _validShipCoordinates.size(); i++)
		if(_validShipCoordinates[i] == damagedCoord)
			_validShipCoordinates.erase(_validShipCoordinates.begin()+i);
}

const bool Ship::getShipStatus() const
{
	return _validShipCoordinates.size();
}

#endif