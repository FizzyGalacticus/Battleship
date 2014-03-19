//Dustin Dodson & Bucky Frost
//Source file for different utilities needed
//CS372 Project 1

#ifndef __UTILITY__FUNCTIONS__
#define __UTILITY__FUNCTIONS__

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <stdlib.h>
#include <string>
using std::string;

inline void wait()
{
	cout << "Press ENTER to continue";
	while(cin.ignore().get() != '\n');	
}

inline const string getUserInput()
{
	string input;
	
	try
	{
		getline(cin, input);
	}
	catch(...)
	{
		throw "Error with taking user input!";
	}
	
	return input;
}

	//***********IF ON WINDOWS**************
	#if defined(__WIN32__) || defined(_WIN32) || defined(_WIN64) || defined(__TOS_WIN__) || defined(__WINDOWS__)

		inline void clearScreen() {system("cls");}

	//**********IF ON LINUX*****************
	#elif defined(__linux__) || defined(linux) || defined(__linux)

		inline void clearScreen() {system("clear");}

	//***********IF ON MAC******************
	#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)

		inline void clearScreen() {system("clear");}

	#endif

#endif