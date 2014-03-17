//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;

#include "osFunctions.cpp"
#include "BoardPrompts.cpp"

Board::Board() : _gridSize(10)
{
	initBoard();
	initShips();
}

Board::Board(const int size) : _gridSize( (size>=5) ? size : 5 )
{
	initBoard();
	initShips();
}

void Board::initBoard()
{
	vector<char> temp(_gridSize, ' ');
	for(int i = 0; i < _gridSize; i++)
	{
		_board.push_back(temp);
	}
}

void Board::assignShipCoordinatesOnBoard(const Ship & currentShip)
{
	vector<Coordinate > coordinates = currentShip.getCoordinates();
		
	for(int i = 0; i < coordinates.size(); i++)
	{
		_board[coordinates[i].second][coordinates[i].first] = 'S';
	}
}

const vector<string> Board::parsePossibleShipDirections(const vector<vector<Coordinate > > allPossibleShipDirections)
{
	vector<string> possibleShipDirections;
	
	for(int i = 0; i < allPossibleShipDirections.size(); i++)
	{
		if(i == 0 && allPossibleShipDirections[i].size()) possibleShipDirections.push_back("Up");
		else if(i == 1 && allPossibleShipDirections[i].size()) possibleShipDirections.push_back("Down");
		else if(i == 2 && allPossibleShipDirections[i].size()) possibleShipDirections.push_back("Left");
		else if(i == 3 && allPossibleShipDirections[i].size()) possibleShipDirections.push_back("Right");
	}
	
	return possibleShipDirections;
}

void Board::initShips()
{
	for(map<string,int>::const_iterator itr = Ship::_shipTypes.begin(); itr != Ship::_shipTypes.end(); itr++)
		_ships.push_back(Ship(itr->first));
	
	bool isNotValidInput = true;
	string input;
	Coordinate inputCoordinate;
	
	//Go through each ship
	for(int i = 0; i < _ships.size(); i++)
	{
		const int & shipHitpoints = _ships[i].getNumberOfHitPoints();
		const string & shipName = _ships[i].getNameOfShip();
		
		//Get proper input of coordinates
		while(isNotValidInput)
		{
			printBoard(cout);
			
			input = initialShipCoordinatePrompt(shipName, shipHitpoints);
			
			inputCoordinate = parseUserInput(input);
			
			clearScreen();
			
			//Set proper coordinates to ship
			if(inputCoordinate.first >= 0 && inputCoordinate.second >= 0)
			{
				isNotValidInput = false;
				const vector<vector<Coordinate > > possibleShipDirections = getPossibleShipDirection(inputCoordinate, shipHitpoints);
				char directionInput = 0;
				
				while((directionInput != 'U' && directionInput != 'u') &&
					  (directionInput != 'D' && directionInput != 'd') &&
					  (directionInput != 'L' && directionInput != 'l') &&
					  (directionInput != 'R' && directionInput != 'r'))
				{
					printBoard(cout);
					
					directionInput = shipDirectionalPrompt(possibleShipDirections);
					
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

Coordinate Board::parseUserInput(const string & input)
{
	static const char upperAlphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
			   lowerAlphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
		'n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	static map<char,int> asciiNums;
	
	Coordinate retCoords(-1,-1);
	
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
		else if(lowerAlphabet[i] == input[0])
		{
			retCoords.second = i;
			break;
		}
	}
		
	return retCoords;
}

//Works!
vector<Coordinate> Board::getLeftAndUpCoordinates(const Coordinate & baseCoords, const char & checkAxis, const int & spaceNeeded)
{
	vector<Coordinate> direction, checked;
	const bool checkLeft = (checkAxis == 'L')?true:false;
	const int checkCoordinate = (checkLeft)?baseCoords.second:baseCoords.first;
	
	if((checkCoordinate - spaceNeeded) >= 0)
	{
		for(int i = (checkCoordinate - spaceNeeded); i <= checkCoordinate; i++)
		{
			Coordinate tempCoord = (checkLeft)?Coordinate(baseCoords.first,i):Coordinate(i,baseCoords.second);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == checkCoordinate) direction = checked;
		}
	}
	
	return direction;
}

//Does not work for Down coordinates!
vector<Coordinate> Board::getRightAndDownCoordinates(const Coordinate & baseCoords, const char & checkAxis, const int & spaceNeeded)
{
	vector<Coordinate> direction, checked;
	const bool checkRight = (checkAxis == 'R')?true:false;
	const int checkCoordinate = (checkRight)?baseCoords.second:baseCoords.first;
	
	if((checkCoordinate + spaceNeeded) < (_gridSize-1))
	{
		for(int i = checkCoordinate; i <= (checkCoordinate + spaceNeeded); i++)
		{
			Coordinate tempCoord = (checkRight)?Coordinate(baseCoords.first,i):Coordinate(i,baseCoords.second);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == (checkCoordinate + spaceNeeded)) direction = checked;
		}
	}
	
	if(!checkRight) cout << "Looking downward and found these available spaces:" << endl;
	for(int i = 0; i < direction.size(); i++)
		cout << '[' << direction[i].first << ',' << direction[i].second << ']' << endl;
	
	return direction;
}

const vector<vector<Coordinate > > Board::getPossibleShipDirection(const Coordinate & userGivenCoords, const int & shipHitpoints)
{
	vector<vector<Coordinate > > possibleDirections;
	vector<Coordinate > up,down,left,right;
	const int xCoord = userGivenCoords.first, yCoord = userGivenCoords.second, spaceNeeded = (shipHitpoints - 1);
	
	up = getLeftAndUpCoordinates(userGivenCoords, 'U', spaceNeeded);
	down = getRightAndDownCoordinates(userGivenCoords, 'D', spaceNeeded);
	left = getLeftAndUpCoordinates(userGivenCoords, 'L', spaceNeeded);
	right = getRightAndDownCoordinates(userGivenCoords, 'R', spaceNeeded);
	
	/*
	//Check left
	if((yCoord - spaceNeeded) >= 0)
	{
		vector<Coordinate > checked;
		for(int i = (yCoord - spaceNeeded); i <= yCoord; i++)
		{
			Coordinate tempCoord(xCoord,i);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == yCoord) left = checked;
		}
	}
	
	//Check right
	if((yCoord + spaceNeeded) < (_gridSize-1))
	{
		vector<Coordinate > checked;
		
		for(int i = yCoord; i <= (yCoord + spaceNeeded); i++)
		{
			Coordinate tempCoord(xCoord,i);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == (yCoord + spaceNeeded)) right = checked;
		}
	}
	
	//Check up
	if((xCoord - spaceNeeded) >= 0)
	{
		vector<Coordinate > checked;
		for(int i = (xCoord - spaceNeeded); i <= xCoord; i++)
		{
			Coordinate tempCoord(i,yCoord);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == xCoord) up = checked;
		}
	}
	
	//Check down
	if((xCoord + spaceNeeded) < (_gridSize-1))
	{
		vector<Coordinate > checked;
		for(int i = xCoord; i <= (xCoord + spaceNeeded); i++)
		{
			Coordinate tempCoord(i,yCoord);
			checked.push_back(tempCoord);
			
			if(isOccupied(tempCoord)) break;
			else if(i == (xCoord + spaceNeeded)) down = checked;
		}
	}*/
	
	possibleDirections.push_back(up);
	possibleDirections.push_back(down);
	possibleDirections.push_back(left);
	possibleDirections.push_back(right);
	
	return possibleDirections;	
}

const bool Board::isOccupied(const Coordinate & coords)
{
	if( _board[coords.second][coords.first] == 'O' || _board[coords.second][coords.first] == ' ') return false;
	else if( _board[coords.second][coords.first] == 'X' || _board[coords.second][coords.first] == 'S') return true;
}

const char Board::getCellContents(const int xCoord, const int yCoord)
{
	return _board[yCoord][xCoord];
}

void Board::setCellContents(const int xCoord, const int yCoord, const char cellContent)
{
	_board[yCoord][xCoord] = cellContent;
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
			out << "| " << getCellContents(i,j) << ' ';
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

const int Board::findShipWithCoordinates(const Coordinate searchCoord) const
{
	for(int i = 0; i < _ships.size(); i++)
	{
		vector<Coordinate > shipCoordinates = _ships[i].getCoordinates();
		for(int j = 0; j < shipCoordinates.size(); j++)
			if(searchCoord == shipCoordinates[j]) return i;
	}
	
	return -1;
}

void Board::attackBoardCoordinate()
{
	string input;
	Coordinate inputCoordinates(-1,-1);
	
	while(inputCoordinates.first < 0 || inputCoordinates.second < 0)
	{
		input = attackCoordinatePrompt();
		
		clearScreen();
		
		inputCoordinates = parseUserInput(input);
		
		if(inputCoordinates.first < 0 || inputCoordinates.second < 0)
		{
			cout << "That was not valid input" << endl;
			wait();
			clearScreen();
		}
		else
		{
			if(isOccupied(inputCoordinates))
			{
				const int index = findShipWithCoordinates(inputCoordinates);
				_ships[index].sustainDamage(inputCoordinates);
				setCellContents(inputCoordinates.first, inputCoordinates.second, 'X');
				cout << "Hit!" << endl;
				wait();
				clearScreen();
			}
			else
			{
				setCellContents(inputCoordinates.first, inputCoordinates.second, 'O');
				cout << "Miss!" << endl;
				wait();
				clearScreen();
			}
		}
	}
}

#endif
