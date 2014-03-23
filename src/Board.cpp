//Dustin Dodson & Bucky Frost
//Source file for Board class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__BOARD__CPP
#define __BATTLESHIP__BOARD__CPP

#include "Board.h"
#include <iostream>
using std::ostream;
using std::endl;

#include "utilities.cpp"
#include "BoardPrompts.cpp"

Board::Board(ostream & streamToOutputTo) : _gridSize(10), _outputStream(streamToOutputTo)
{
	initBoard();
	initShips();
}

Board::Board(ostream & streamToOutputTo, const int size) : _gridSize( (size>=5) ? size : 5 ), _outputStream(streamToOutputTo)
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

void Board::initShips()
{
	//Pushes one of each Ship type to _shipsInPlay vector
	for(map<string,int>::const_iterator itr = Ship::_shipTypes.begin(); itr != Ship::_shipTypes.end(); itr++)
		_shipsInPlay.push_back(Ship(itr->first));
	
	bool isNotValidInput = true;
	string input;
	Coordinate inputCoordinate;
	
	//Go through each ship
	for(int i = 0; i < _shipsInPlay.size(); i++)
	{
		const int & shipHitpoints = _shipsInPlay[i].getNumberOfHitPoints();
		const string & shipName = _shipsInPlay[i].getNameOfShip();
		
		//Get proper input of coordinates
		while(isNotValidInput)
		{
			printBoard(false);
			
			input = initialShipCoordinatePrompt(shipName, shipHitpoints);
			
			inputCoordinate = parseUserInput(input);
			
			clearScreen();
			
			//Set proper coordinates to ship
			if(inputCoordinate.first >= 0 && inputCoordinate.second >= 0)
			{
				const vector<vector<Coordinate > > possibleShipDirections = getPossibleShipDirection(inputCoordinate, shipHitpoints);
				if(possibleShipDirections.size()) isNotValidInput = false;
				else continue;
				
				char directionInput = 0;
				
				while((directionInput != 'U' && directionInput != 'u') &&
					  (directionInput != 'D' && directionInput != 'd') &&
					  (directionInput != 'L' && directionInput != 'l') &&
					  (directionInput != 'R' && directionInput != 'r'))
				{
					printBoard(false);
					
					directionInput = shipOrientationPrompt(possibleShipDirections);
					
					clearScreen();
					
					switch(directionInput)
					{
						case 'U':
						case 'u':
							if(possibleShipDirections[0].size())
							{
								_shipsInPlay[i].setCoordinates(possibleShipDirections[0]);
							}
						break;
						case 'D':
						case 'd':
							if(possibleShipDirections[1].size())
							{
								_shipsInPlay[i].setCoordinates(possibleShipDirections[1]);
							}
						break;
						case 'L':
						case 'l':
							if(possibleShipDirections[2].size())
							{
								_shipsInPlay[i].setCoordinates(possibleShipDirections[2]);
							}
						break;
						case 'R':
						case 'r':
							if(possibleShipDirections[3].size())
							{
								_shipsInPlay[i].setCoordinates(possibleShipDirections[3]);
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
		assignShipCoordinatesOnBoard(_shipsInPlay[i]);
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

//This function uses ternary operator to differentiate between different directions for our Ship.
vector<Coordinate> Board::computeLeftOrUpCoordinates(const Coordinate & baseCoords, const char & checkAxis, const int & spaceNeeded)
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

//This function uses ternary operator to differentiate between different directions for our Ship.
vector<Coordinate> Board::computeRightOrDownCoordinates(const Coordinate & baseCoords, const char & checkAxis, const int & spaceNeeded)
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
	
	return direction;
}

const vector<vector<Coordinate > > Board::getPossibleShipDirection(const Coordinate & userGivenCoords, const int & shipHitpoints)
{
	vector<vector<Coordinate > > possibleDirections;
	vector<Coordinate > up,down,left,right;
	const int xCoord = userGivenCoords.first, yCoord = userGivenCoords.second, spaceNeeded = (shipHitpoints - 1);
	
	up = computeLeftOrUpCoordinates(userGivenCoords, 'U', spaceNeeded);
	down = computeRightOrDownCoordinates(userGivenCoords, 'D', spaceNeeded);
	left = computeLeftOrUpCoordinates(userGivenCoords, 'L', spaceNeeded);
	right = computeRightOrDownCoordinates(userGivenCoords, 'R', spaceNeeded);
	
	if(up.size()) possibleDirections.push_back(up);
	if(down.size()) possibleDirections.push_back(down);
	if(left.size()) possibleDirections.push_back(left);
	if(right.size()) possibleDirections.push_back(right);
	
	return possibleDirections;	
}

const char Board::getCellContents(const Coordinate & cellLocation) const
{
	const int xCoord = cellLocation.first, yCoord = cellLocation.second;
	return _board[yCoord][xCoord];
}

void Board::setCellContents(Coordinate cellLocation, const char cellContent)
{
	const int xCoord = cellLocation.first, yCoord = cellLocation.second;
	_board[yCoord][xCoord] = cellContent;
}

const int Board::findShipWithCoordinates(const Coordinate searchCoord) const
{
	for(int i = 0; i < _shipsInPlay.size(); i++)
	{
		vector<Coordinate > shipCoordinates = _shipsInPlay[i].getCoordinates();
		for(int j = 0; j < shipCoordinates.size(); j++)
			if(searchCoord == shipCoordinates[j]) return i;
	}
	
	return -1;
}

const bool Board::shipsStillActive() const
{
	return _shipsInPlay.size();
}

void Board::attackBoardCoordinate()
{
	string input;
	Coordinate inputCoordinates(-1,-1);
	
	while(inputCoordinates.first < 0 || inputCoordinates.second < 0)
	{
		input = attackCoordinatePrompt();
		
		inputCoordinates = parseUserInput(input);
		
		if(inputCoordinates.first < 0 || inputCoordinates.second < 0)
		{
			_outputStream << "That was not valid input." << endl;
			wait();
		}
		else
		{
			if(isOccupied(inputCoordinates))
			{
				const int index = findShipWithCoordinates(inputCoordinates);
				_shipsInPlay[index].sustainDamage(inputCoordinates);
				
				setCellContents(inputCoordinates, 'X');
				
				_outputStream << "Hit!" << endl;
				wait();
			}
			else
			{
				setCellContents(inputCoordinates, 'O');
				_outputStream << "Miss!" << endl;
				wait();
			}
		}
	}
	
	deadShipRemover();
}

void Board::deadShipRemover()
{
	for(int i = 0; i < _shipsInPlay.size(); i++)
	{
		if(!_shipsInPlay[i].getShipStatus())
			_shipsInPlay.erase(_shipsInPlay.begin()+i);
	}
}

const bool Board::isOccupied(const Coordinate & coords) const
{
	if( _board[coords.second][coords.first] == 'X' || _board[coords.second][coords.first] == 'S') return true;
	return false;
}

void Board::printBoard(const bool isPublic) const
{	
	//print row index
	const char rowHeaders[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	
	for(int i = 0; i < _gridSize; i++) _outputStream  << "   " << rowHeaders[i];
	_outputStream << endl;
	
	_outputStream << ' ' << getEndString() << endl;
	_outputStream << getMidString() << endl;
	
	for(int row = 0; row < _gridSize; row++)
	{
		_outputStream << row;
		for(int column = 0; column < _gridSize; column++)
		{
			char charToPrint = 0;
			if(isPublic && getCellContents(Coordinate(row,column)) == 'S') charToPrint = ' ';
			else charToPrint = getCellContents(Coordinate(row,column));
			_outputStream << "| " << charToPrint << ' ';
		}
		_outputStream << '|' << endl;
		_outputStream << getMidString() << endl;
	}
	
	_outputStream << ' ' << getEndString() << endl;
}

const string Board::getEndString() const
{
	string temp;
	
	temp += '+';
	for(int i = 0; i < (_gridSize*4-1); i++) temp += '-';
	temp += '+';
	
	return temp;
}

const string Board::getMidString() const
{
	string temp;
	
	for(int i = 0; i < _gridSize; i++) temp += " | -";
	temp += " |";
	
	return temp;
}

#endif
