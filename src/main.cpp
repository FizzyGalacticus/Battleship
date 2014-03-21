//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "utilities.cpp"
#include "Game.h"

int main(const int argc, const char* argv[])
{
	clearScreen();
	
	vector<string> backgroundMusicFileNames;
	
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
			backgroundMusicFileNames.push_back(argv[i]);
	}
	
	Game myGame;
	myGame.setBackgroundMusicFiles(backgroundMusicFileNames);
	myGame.preGame();
}
