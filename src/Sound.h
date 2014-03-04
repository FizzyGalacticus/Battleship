//Dustin Dodson & Bucky Frost
//Source file for Sound class header
//CS372 Project 1

#ifndef __BATTLESHIP__SOUNDS__H
#define __BATTLESHIP__SOUNDS__H

#include "irrKlang/include/irrKlang.h"
using namespace irrklang;

// link with irrKlang.dll
#pragma comment(lib, "irrKlang\lib\Win32-visualStudio\irrKlang.lib")
#pragma comment(lib, "irrKlang\lib\Win32-gcc\libirrKlang.a")

#include <vector>
using std::vector;

#include <string>
using std::string;

class Sound
{
	public:
		Sound(const string audioFilename);
		~Sound();
		static void pauseAudio();
		static void unpauseAudio();
	private:
		Sound();
		static vector<ISoundSource*> _audioStreams;
		static ISoundEngine * _engine;
};

#endif
