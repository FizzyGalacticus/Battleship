//Dustin Dodson & Bucky Frost
//Source file for Game class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__GAME__CPP
#define __BATTLESHIP__GAME__CPP

#include "Game.h"
#include "osFunctions.cpp"
#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
using std::exit;

vector<string> Game::_backgroundMusicFileNames;
int Game::_activePlayerIndex(0);

Game::~Game()
{
	for(int i = 0; i < _players.size(); i++)
		delete _players[i];
}

void Game::initGame()
{
	for(int i = 0; i < 2; i++)
	{
		string name;
		
		cout << "Please enter your name: " << endl;
		cin >> name;
		cin.ignore(1000, '\n');
		
		Player * myPlayer = new Player(name);
		
		_players.push_back(myPlayer);
	}
	
	mainGameLoop();
}

void Game::preGame()
{
	while(true)
	{
		const int menuSelection = mainMenu();
		
		switch(menuSelection)
		{
			case 1:
				initGame();
			break;
			case 2:
			case 3:
				cout << "This feature has not yet been implemented!" << endl;
				cout << "Pay us more money, and we'll throw it in!" << endl;
				wait();
				clearScreen();
			break;
			case 4:
				exit(0);
			break;
		}
	}
}

void Game::mainGameLoop()
{
	while(allPlayersAreStillAlive())
	{
		printPlayerBoards();
		_players[_activePlayerIndex]->attackOpponent(_players[( (_activePlayerIndex == 0) ? 1 : 0 )]);
		clearScreen();
	}
	
	printWinnerMessage(indexToWinningPlayer());
}

const bool Game::allPlayersAreStillAlive()
{
	for(int i = 0; i < _players.size(); i++)
		if(!_players[i]->isStillActive()) return false;
	
	return true;
}

void Game::printPlayerBoards()
{
	_players[( (_activePlayerIndex == 0) ? 1 : 0 )]->printBoard(false);
	_players[_activePlayerIndex]->printBoard(true);
}

const int Game::indexToWinningPlayer() const
{
	int winner = 0;
	
	for(int i = 0; i < _players.size(); i++)
		if(_players[i]->isStillActive()) winner = i;
		
	return winner;
}

void Game::printWinnerMessage(const int indexToWinner) const
{
	cout << "Congratulations to " << _players[indexToWinner]->getPlayerName() << ", you are the winner!" << endl;
	wait();
	clearScreen();
}

#endif
