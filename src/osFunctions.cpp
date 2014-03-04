#include <stdlib.h>

#if defined(__WIN32__) || defined(_WIN32) || defined(_WIN64) || defined(__TOS_WIN__) || defined(__WINDOWS__)

void clearScreen() {system("cls");}

#elif defined(__linux__) || defined(linux) || defined(__linux)

void clearScreen() {system("clear");}

#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)

void clearScreen() {system("clear");}

#endif