//Dustin Dodson & Bucky Frost
//Main source file for Battleship
//CS372 Project 1

#include "menues.cpp"
#include "Sound.h"

int main(const int argc, const char* argv[])
{
	Sound backgroundMusic("Media/emergency007.mp3");
	mainMenu();
	pauseMenu();
	while(getch() != 'q');
	return 0;
}