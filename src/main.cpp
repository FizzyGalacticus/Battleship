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
	clearScreen();
	
	/*//TESTING BACKGROUND MUSIC
	vector<string> backgroundMusicFileNames;
	
	backgroundMusicFileNames.push_back("../Media/emergency007.mp3");
	
	BackgroundAudio backgroundMusic(backgroundMusicFileNames);
	backgroundMusic.startBackgroundAudio(0);
	
	clearScreen();
	
	//TESTING SHIP CLASS
	vector<Ship> myShips;
	myShips.push_back(Ship("Battleship"));
	myShips.push_back(Ship("Aircraft Carrier"));
	myShips.push_back(Ship("Submarine"));
	myShips.push_back(Ship("Destroyer"));
	myShips.push_back(Ship("Cruiser"));
	
	for(vector<Ship>::iterator itr = myShips.begin(); itr != myShips.end(); itr++)
	{
		cout << "Name of ship: " << itr->getNameOfShip() << endl;
		cout << "# of Hitpoints: " << itr->getNumberOfHitPoints() << endl;
	}*/
	
	//TESTING BOARD CLASS
	Board myboard;
	
	return 0;
}
