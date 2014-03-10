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

class Ship
{
	public:
		const vector<pair<int,int> > getCoordinates();
		const string & getNameOfShip();
	private:
		vector<pair<int,int> > _coordinates;
		vector<int> _activeCoordIndex; //Better name?
		const string _nameOfShip;
};

#endif