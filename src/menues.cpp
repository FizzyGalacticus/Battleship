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

void mainMenu()
{
	int input(0);
	
	while(input < 1 || input > 4)
	{
		cout << "Please choose an option:" << endl;
		cout << "1. Start Game" << endl;
		cout << "2. Options" << endl;
		cout << "3. About" << endl;
		cout << "4. Exit" << endl;
		cin >> input;
		clearScreen();
		
		switch(input)
		{
			case 1:
				
			break;
			case 2:
				
			break;
			case 3:
				
			break;
			case 4:
				
			break;
			default:
				cout << "That was not an option." << endl;
			break;
		}
	}
}

//Menu for when the game is paused.
void pauseMenu()
{
	Sound::pauseAudio();
	cout << "GAME PAUSED" << endl;
	cout << "Press 'p' to unpause" << endl;
	
	while(getchar() != 'p');
	Sound::unpauseAudio();
	clearScreen();
}

#endif
