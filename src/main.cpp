//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "menues.cpp"
#include "Sound.h"
#include <stdio.h>

int main(const int argc, const char* argv[])
{
	Sound backgroundMusic("Media/emergency007.mp3");
	mainMenu();
	pauseMenu();
	while(getchar() != 'q');
	return 0;
}
