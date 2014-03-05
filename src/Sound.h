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
		~Sound();
		static void pauseAudio();
		static void unpauseAudio();
	protected:
		ISoundSource* initSound(const string audioFilename);
		Sound() {}
		static vector<ISoundSource*> _audioStreams;
		static ISoundEngine * _engine;
};

class BackgroundAudio : public Sound
{
	public:
		BackgroundAudio(const string audioFilename);
		~BackgroundAudio();
	private:
		ISoundSource* _stream;
};

class SoundFXAudio : public Sound
{
	public:
		SoundFXAudio(const string audioFilename);
		~SoundFXAudio();
	private:
		ISoundSource* _stream;
};

#endif
