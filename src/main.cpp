//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "menues.cpp"
#include "Sound.h"
#include <stdio.h>
#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;

int main(const int argc, const char* argv[])
{
	BackgroundAudio backgroundMusic("Media/emergency007.mp3");
	mainMenu();
	pauseMenu();

	Board myBoard;
	
	myBoard.printBoard(cout);
	
	cout << "Press 'q' to quit" << endl;
	while(getchar() != 'q');
	
	return 0;
}
