//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "osFunctions.cpp"


Board::Board() : _gridSize(10)
{
	initBoard();
	initShips();
}

Board::Board(const int size) : _gridSize(size)
{
	initBoard();
	initShips();
}

void Board::initBoard()
{
	vector<bool> temp(_gridSize, false);
	for(int i = 0; i < _gridSize; i++)
	{
		_board.push_back(temp);
	}
}

void Board::assignShipCoordinatesOnBoard(const Ship & currentShip)
{
	vector<pair<int, int> > coordinates = currentShip.getCoordinates();
		
	for(int i = 0; i < coordinates.size(); i++)
	{
		_board[coordinates[i].second][coordinates[i].first] = true;
	}
}

void Board::initShips()
{
	for(map<string,int>::const_iterator itr = Ship::_shipTypes.begin(); itr != Ship::_shipTypes.end(); itr++)
		_ships.push_back(Ship(itr->first));
	
	bool isNotValidInput = true;
	string input;
	pair<int,int> inputCoordinate;
	
	//Go through each ship
	for(int i = 0; i < _ships.size(); i++)
	{
		const int & shipHitpoints = _ships[i].getNumberOfHitPoints();
		const string & shipName = _ships[i].getNameOfShip();
		
		//Get proper input of coordinates
		while(isNotValidInput)
		{
			printBoard(cout);
			
			cout << "Please type desired coordinates for front of " << shipName
				<< endl << '(' << shipHitpoints << " total spaces needed) " << "(example: 'I4'): ";
			cin >> input;
			cin.ignore(1000, '\n');
			
			inputCoordinate = parseUserInput(input);
			
			clearScreen();
			
			//Set proper coordinates to ship
			if(inputCoordinate.first >= 0 && inputCoordinate.second >= 0)
			{
				isNotValidInput = false;
				const vector<vector<pair<int, int> > > possibleShipDirections = getPossibleShipDirection(inputCoordinate, shipHitpoints);
				char directionInput = 0;
				
				while((directionInput != 'U' && directionInput != 'u') &&
					  (directionInput != 'D' && directionInput != 'd') &&
					  (directionInput != 'L' && directionInput != 'l') &&
					  (directionInput != 'R' && directionInput != 'r'))
				{
					printBoard(cout);
					
					cout << "Please enter a direction (UDLR) you would like to face your ship." << endl;
					cout << "Your options are: " << endl;
					for(int j = 0; j < possibleShipDirections.size(); j++)
					{
						if(j == 0 && possibleShipDirections[j].size()) cout << "Up" << endl;
						else if(j == 1 && possibleShipDirections[j].size()) cout << "Down" << endl;
						else if(j == 2 && possibleShipDirections[j].size()) cout << "Left" << endl;
						else if(j == 3 && possibleShipDirections[j].size()) cout << "Right" << endl;
					}
					
					directionInput = getchar();
					
					clearScreen();
					
					switch(directionInput)
					{
						case 'U':
						case 'u':
							if(possibleShipDirections[0].size())
							{
								_ships[i].setCoordinates(possibleShipDirections[0]);
							}
						break;
						case 'D':
						case 'd':
							if(possibleShipDirections[1].size())
							{
								_ships[i].setCoordinates(possibleShipDirections[1]);
							}
						break;
						case 'L':
						case 'l':
							if(possibleShipDirections[2].size())
							{
								_ships[i].setCoordinates(possibleShipDirections[2]);
							}
						break;
						case 'R':
						case 'r':
							if(possibleShipDirections[3].size())
							{
								_ships[i].setCoordinates(possibleShipDirections[3]);
							}
						break;
						default:
							cout << "Bad Selection. Please try again." << endl;
						break;
					}
				}
			}
			else
			{
				cout << "Error: Input invalid." << endl;
			}
		}
		
		isNotValidInput = true;
		assignShipCoordinatesOnBoard(_ships[i]);
	}
		
	printBoard(cout);
}

pair<int,int> Board::parseUserInput(const string & input)
{
	static const char upperAlphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
			   lowerAlphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
		'n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	static map<char,int> asciiNums;
	
	pair<int,int> retCoords(-1,-1);
	
	if(asciiNums.size() == 0)
		for(int i = 48; i < 58; i++)
			asciiNums[i] = (i-48);
	
	for(map<char,int>::iterator itr = asciiNums.begin(); itr != asciiNums.end(); itr++)
		if(itr->first == input[1]) retCoords.first = itr->second;
	
	for(int i = 0; i < 26; i++)
	{
		if(upperAlphabet[i] == input[0])
		{
			retCoords.second = i;
			break;
		}
		if(lowerAlphabet[i] == input[0])
		{
			retCoords.second = i;
			break;
		}
	}
		
	return retCoords;
}

const vector<vector<pair<int, int> > > Board::getPossibleShipDirection(const pair<int,int> & userGivenCoords, const int & shipHitpoints)
{
	vector<vector<pair<int, int> > > possibleDirections;
	vector<pair<int, int> > up,down,left,right;
	const int xCoord = userGivenCoords.first, yCoord = userGivenCoords.second, spaceNeeded = (shipHitpoints - 1);
	
	//Check left
	if((yCoord - spaceNeeded) >= 0)
	{
		vector<pair<int, int> > checked;
		for(int i = (yCoord - spaceNeeded); i <= yCoord; i++)
		{
			checked.push_back(pair<int,int>(xCoord,i));
			
			if(isOccupied(xCoord,i)) break;
			else if(i == yCoord) left = checked;
		}
	}
	
	//Check right
	if((yCoord + spaceNeeded) < (_gridSize-1))
	{
		vector<pair<int, int> > checked;
		
		for(int i = yCoord; i <= (yCoord + spaceNeeded); i++)
		{
			checked.push_back(pair<int,int>(xCoord,i));
			
			if(isOccupied(xCoord,i)) break;
			else if(i == (yCoord + spaceNeeded)) right = checked;
		}
	}
	
	//Check up
	if((xCoord - spaceNeeded) >= 0)
	{
		vector<pair<int, int> > checked;
		for(int i = (xCoord - spaceNeeded); i <= xCoord; i++)
		{
			checked.push_back(pair<int,int>(i,yCoord));
			
			if(isOccupied(i,yCoord)) break;
			else if(i == xCoord) up = checked;
		}
	}
	
	//Check down
	if((xCoord + spaceNeeded) < (_gridSize-1))
	{
		vector<pair<int, int> > checked;
		for(int i = xCoord; i <= (xCoord + spaceNeeded); i++)
		{
			checked.push_back(pair<int,int>(i,yCoord));
			
			if(isOccupied(i,yCoord)) break;
			else if(i == (xCoord + spaceNeeded)) down = checked;
		}
	}
	
	/*
	possibleDirections.push_back(getUpAndLeftCoords(userGivenCoords, spaceNeeded, 'U'));
	possibleDirections.push_back(getDownAndRightCoords(userGivenCoords, spaceNeeded, 'D'));
	possibleDirections.push_back(getUpAndLeftCoords(userGivenCoords, spaceNeeded, 'L'));
	possibleDirections.push_back(getDownAndRightCoords(userGivenCoords, spaceNeeded, 'R'));
	*/
	
	possibleDirections.push_back(up);
	possibleDirections.push_back(down);
	possibleDirections.push_back(left);
	possibleDirections.push_back(right);
	
	return possibleDirections;	
}

//WILL NOT WORK
const vector<pair<int, int> > Board::getDownAndRightCoords(const pair<int,int> & baseCoords, const int spaceNeeded, const char direction)
{
	//Vectors that are to hold coordinates, one for coordinates that we add as we check them,
	//the other for all coordinates once we verify that the Ship will fit in that area.
	vector<pair<int, int> > possibleCoords, coordsChecked;
	const int xCoord = baseCoords.first, yCoord = baseCoords.second;
	
	if((yCoord + spaceNeeded ) <= (_gridSize - 1))
	{
		//Go through all coordinates that need to be checked
		for(int i = yCoord; i <= (baseCoords.first + spaceNeeded); i++)
		{
			//Add this coordinate to the checked coord vector depending on direction
			coordsChecked.push_back((direction == 'D')?pair<int, int>(xCoord,i):pair<int, int>(i,baseCoords.first));
			
			//Break and return empty vector if any of the spaces contain a ship
			if((direction == 'U')?_board[baseCoords.first][i]:_board[i][baseCoords.first]) break;
			if(i == baseCoords.first && !((direction == 'D')?_board[baseCoords.first][i]:_board[i][baseCoords.first])) possibleCoords = coordsChecked;
		}
	}
	
	return possibleCoords;
}

//WILL NOT WORK
const vector<pair<int, int> > Board::getUpAndLeftCoords(const pair<int,int> & baseCoords, const int spaceNeeded, const char direction)
{
	//Vectors that are to hold coordinates, one for coordinates that we add as we check them,
	//the other for all coordinates once we verify that the Ship will fit in that area.
	vector<pair<int, int> > possibleCoords, coordsChecked;
	
	if((baseCoords.first - spaceNeeded ) >= 0)
	{
		//Go through all coordinates that need to be checked
		for(int i = (baseCoords.first - spaceNeeded); i <= baseCoords.first; i++)
		{
			//Add this coordinate to the checked coord vector depending on direction
			coordsChecked.push_back((direction == 'U')?pair<int, int>(baseCoords.first,i):pair<int, int>(i,baseCoords.first));
			
			//Break and return empty vector if any of the spaces contain a ship
			if((direction == 'U')?_board[baseCoords.first][i]:_board[i][baseCoords.first]) break;
			if(i == baseCoords.first && !((direction == 'U')?_board[baseCoords.first][i]:_board[i][baseCoords.first])) possibleCoords = coordsChecked;
		}
	}
	
	return possibleCoords;
}

const bool Board::isOccupied(const int x, const int y)
{
	return _board[y][x];
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
			out << "| " << (isOccupied(i,j)?'T':' ') << ' ';
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
