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

vector<const Player *> Player::_existingPlayers;
static int _activePlayer(0);

Player::Player(const string & givenName): _name(givenName), _playerBoard()
{
	_existingPlayers.push_back(this);
	selfPositionInPlayers = (_existingPlayers.size()-1);
}

void Player::printOpponentBoard() const
{
	
}

const string & Player::getPlayerName() const
{return _name;}

void Player::attackOpponent()
{
	int userInput(0);
	vector<string> opponentNames;
	
	for(int i = 0; i < _existingPlayers.size(); i++)
	{
		if(i == selfPositionInPlayers) continue;
		opponentNames.push_back(_existingPlayers[i]->getPlayerName());
	}
	
	cout << "Which player would you like to attack?" << endl;
	for(int i = 0; i < opponentNames.size(); i++)
		cout << (i+1) << ". " << opponentNames[i] << endl;
	cin >> userInput;
	cin.ignore(1000,'\n');
	
	
}

#endif