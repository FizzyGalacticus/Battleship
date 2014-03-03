//Test for irrKlang library
//Dustin Dodson
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// include console I/O methods (conio.h for windows, our wrapper in linux)
#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

#include "irrKlang\include\irrKlang.h"
using namespace irrklang;
#pragma comment(lib, "irrKlang\lib\Win32-visualStudio\irrKlang.lib") // link with irrKlang.dll

int main(const int argc, const char * argv[])
{
	// start the sound engine with default parameters
	ISoundEngine* engine = createIrrKlangDevice();

	if (!engine)
		cout << "Failed to start sound engine!" << endl;
	
	// play some sound stream, looped
	engine->play2D("Media/emergency007.mp3", true);
	
	cout << "Press q to quit..." << endl;
	
	while(getch() != 'q');
	
	engine->drop(); // delete engine
	
	return 0;
}