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
#include "Ship.h"
#include <exception>
using std::exception;

int main(const int argc, const char* argv[])
{
	//clearScreen();
	
	//TESTING BACKGROUND MUSIC
	vector<string> backgroundMusicFileNames;
	
	backgroundMusicFileNames.push_back("../Media/emergency007.mp3");
	
	BackgroundAudio backgroundMusic(backgroundMusicFileNames);
	backgroundMusic.startBackgroundAudio(0);
	
	//TESTING SHIP CLASS
	Ship battleship("Battleship");
	cout << "Name of ship: " << battleship.getNameOfShip() << endl;
	cout << "# of Hitpoints: " << battleship.getNumberOfHitPoints() << endl;
	
	//TESTING BOARD CLASS
	//Board myboard;
	//myboard.printBoard(cout);
	
	cout << endl << "Press 'q' to quit" << endl;
	while(getchar() != 'q');
	clearScreen();
	
	return 0;
}
