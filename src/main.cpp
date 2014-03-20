//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "utilities.cpp"
#include "Game.h"

#include <iostream>

int main(const int argc, const char* argv[])
{
	clearScreen();
	
	Game myGame(std::cout);
	myGame.preGame();
	
	return 0;
}
