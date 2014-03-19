//Dustin Dodson & Bucky Frost
//Source file for menu functions
//CS372 Project 1

#ifndef __MENUES__
#define __MENUES__

//I-O libraries needed for printing menu options to screen
//and taking in user input.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <stdio.h>

#include "osFunctions.cpp"
#include "Sound.h"

inline const char mainMenu()
{
	char input;
	
	while(input < 1 || input > 4)
	{
		cout << "Please choose an option:" << endl;
		cout << "1. Start Game" << endl;
		cout << "2. Options" << endl;
		cout << "3. About" << endl;
		cout << "4. Exit" << endl;
		input = (getUserInput()[0]);
		clearScreen();
		
		if(input < '1' || input > '4') cout << "That was not an option." << endl;
		else return input;
	}
}

//Menu for when the game is paused.
inline void pauseMenu()
{
	Sound::pauseAudio();
	cout << "GAME PAUSED" << endl;
	cout << "Press 'p' to unpause" << endl;
	
	while(getchar() != 'p');
	Sound::unpauseAudio();
	clearScreen();
}

#endif
