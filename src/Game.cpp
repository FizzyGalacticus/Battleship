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

void Game::initGame()
{
	for(int i = 0; i < 2; i++)
	{
		string name;
		
		cout << "Please enter your name: " << endl;
		cin >> name;
		cin.ignore(1000, '\n');
		
		Player myPlayer(name);
		
		_players.push_back(&myPlayer);
	}
	
	mainGameLoop();
}

void Game::preGame()
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

void Game::mainGameLoop()
{
	while(allPlayersAreStillAlive())
	{
		printPlayerBoards();
	}
}

const bool Game::allPlayersAreStillAlive()
{
	for(int i = 0; i < _players.size(); i++)
		if(!_players[i]->isStillActive()) return false;
	
	return true;
}

void Game::printPlayerBoards()
{
	_players[( (_activePlayerIndex == 0) ? 0 : 1 )]->printBoard(false);
	_players[_activePlayerIndex]->printBoard(true);
}

#endif