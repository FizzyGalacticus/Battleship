//Dustin Dodson & Bucky Frost
//Source file for Ship class header
//CS372 Project 1

#ifndef __BATTLESHIP__SHIP__H
#define __BATTLESHIP__SHIP__H

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include <string>
using std::string;

#include <map>
using std::map;

class Ship
{
	public:
		const vector<pair<int,int> > getCoordinates() const;
		const string & getNameOfShip() const;
		const bool sustainDamage(const pair<int,int>);
		Ship(const string);
		const int & getNumberOfHitPoints();
	private:
		Ship();
		vector<pair<int,int> > _coordinates;
		vector<int> _activeCoordIndex; //Better name?
		string _nameOfShip;
		static const map<string,int> createShipTypes();
		static const map<string,int> _shipTypes;
		int _hitPoints;
};

#endif