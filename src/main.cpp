//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "osFunctions.cpp"
#include "Game.h"

int main(const int argc, const char* argv[])
{
	clearScreen();
	
	Game myGame;
	myGame.preGame();
	
	return 0;
}
