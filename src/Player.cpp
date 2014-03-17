//Dustin Dodson & Bucky Frost
//Source file for Player class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__PLAYER__CPP
#define __BATTLESHIP__PLAYER__CPP

#include "Player.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;

vector<Player *> Player::_existingPlayers;
static int _activePlayer(0);

Player::Player(const string & givenName): _name(givenName), _playerBoard()
{
	_existingPlayers.push_back(this);
	selfPositionInPlayers = (_existingPlayers.size()-1);
}

void Player::printPublicBoard()
{
	_playerBoard.printBoard(cout, true);
}

const string & Player::getPlayerName() const
{return _name;}

void Player::attackOpponent()
{
	int userInput(0), counter(1);
	vector<pair<string, Player *> > opponents;
	
	for(int i = 0; i < _existingPlayers.size(); i++)
	{
		if(i == selfPositionInPlayers) continue;
		opponents.push_back(pair<string,Player *>(_existingPlayers[i]->getPlayerName(), _existingPlayers[i]));
	}
	
	cout << "Which player would you like to attack?" << endl;
	for(int i = 0; i < opponents.size(); i++)
		cout << (i+1) << ". " << opponents[i].first << endl;
	cin >> userInput;
	cin.ignore(1000,'\n');
	
	opponents[userInput-1].second->printPublicBoard();
	opponents[userInput-1].second->_playerBoard.attackBoardCoordinate();
}

const bool & Player::isStillActive()
{
	return _playerBoard.shipsStillActive();
}

#endif