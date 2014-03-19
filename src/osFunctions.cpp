//Dustin Dodson & Bucky Frost
//Source file for Operating System specific functions
//CS372 Project 1

#ifndef __OS__FUNCTIONS__
#define __OS__FUNCTIONS__

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

inline void wait()
{
	cout << "Press ENTER to continue";
	while(getchar() != '\n');
}

#include <stdlib.h>

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
