//Dustin Dodson & Bucky Frost
//Source file for Game class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__GAME__CPP
#define __BATTLESHIP__GAME__CPP

#include "Game.h"
#include "utilities.cpp"
#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;

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
		cout << "Player #" << (i+1) << ", please enter your name: " << endl;
		const string name = getUserInput();
		
		Player * myPlayer = new Player(name);
		
		_players.push_back(myPlayer);
	}
	
	mainGameLoop();
}

void Game::preGame()
{
	BackgroundAudio backgroundMusic;
	
	if(_backgroundMusicFileNames.size())
	{
		backgroundMusic.initBackgroundAudio(_backgroundMusicFileNames);
		backgroundMusic.startBackgroundAudio(0);
	}
	
	while(true)
	{
		const char menuSelection = mainMenu();
		
		switch(menuSelection)
		{
			case '1':
				initGame();
			break;
			case '2':
			case '3':
				cout << "This feature has not yet been implemented!" << endl;
				cout << "Pay us more money, and we'll throw it in!" << endl;
				wait();
				clearScreen();
			break;
			case '4':
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
		
		_activePlayerIndex = ((_activePlayerIndex == 0) ? 1 : 0);
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
	_players[( (_activePlayerIndex == 0) ? 1 : 0 )]->printBoard(true);
	_players[_activePlayerIndex]->printBoard(false);
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

void Game::setBackgroundMusicFiles(vector<string> & fileNames)
{
	_backgroundMusicFileNames = fileNames;
}

#endif
