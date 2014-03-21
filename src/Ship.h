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

typedef pair<unsigned int,unsigned int> Coordinate;

class Ship
{
	public:
		//Pre: Must be passed a valid std::string object containing a name specified in implementation. (See createShipTypes())
		//Post: Will create Ship object of the name specified.
		Ship(const string);
		
		//Pre: None.
		//Post: Will return all Ship coordinates.
		const vector<Coordinate > getCoordinates() const;
		
		//Pre: Must be passed a valid std::vector<Coordinate> object.
		//Post: Will set Ship's coordinates.
		void setCoordinates(vector<Coordinate >);
		
		//Pre: None.
		//Post: Will return a std::string object with the name of the Ship.
		const string & getNameOfShip() const;
		
		//Pre: Must be passed a valid Coordinate object.
		//Post: Will remove given Coordinate object from _validShipCoordinates.
		void sustainDamage(const Coordinate);
		
		//Pre: None.
		//Post: Will return true if _validShipCoordinates is still holding at least 1 Coordinate object.
		const bool getShipStatus() const;
		
		//Pre: None.
		//Post: Will return a valid integer object.
		const int & getNumberOfHitPoints() const;
		
		static const map<string,int> _shipTypes;
	private:
		Ship();
		
		vector<Coordinate > _validShipCoordinates;
		string _nameOfShip;
		int _hitPoints;
		
		//Pre: None.
		//Post: Creates different Ship object classifications.
		static const map<string,int> createShipTypes();
};

#endif