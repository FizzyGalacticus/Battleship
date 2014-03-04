#include <stdlib.h>

//***********IF ON WINDOWS**************
#if defined(__WIN32__) || defined(_WIN32) || defined(_WIN64) || defined(__TOS_WIN__) || defined(__WINDOWS__)

	#include <conio.h> //Needed for getch()
	void clearScreen() {system("cls");}

//**********IF ON LINUX*****************
#elif defined(__linux__) || defined(linux) || defined(__linux)

	#include "../common/conio.h" //Needed for getch()
	void clearScreen() {system("clear");}

//***********IF ON MAC******************
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)

	#include "../common/conio.h" //Needed for getch()
	void clearScreen() {system("clear");}

#endif