//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "menues.cpp"
#include "Sound.h"
#include "osFunctions.cpp"
#include <stdio.h>
#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;

int main(const int argc, const char* argv[])
{
	clearScreen();
	
	//TESTING BACKGROUND MUSIC
	vector<string> backgroundMusicFileNames;
	backgroundMusicFileNames.push_back("../Media/Constance.mp3");
	BackgroundAudio backgroundMusic(backgroundMusicFileNames);
	backgroundMusic.startBackgroundMusic();
	
	//TESTING MENU SYSTEM
	mainMenu();
	pauseMenu();

	//TESTING BOARD CLASS
	Board myBoard;
	myBoard.printBoard(cout);
	
	cout << endl << "Press 'q' to quit" << endl;
	while(getchar() != 'q');
	clearScreen();
	
	return 0;
}
