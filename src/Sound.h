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

class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
	public:
		virtual void OnSoundStopped(irrklang::ISound*, irrklang::E_STOP_EVENT_CAUSE, void*);
};

//Base sound class used for initializing main sound engine and keeping track of all sound sources. Cannot be created explicitly, only child classes can be created.
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

//Child of Sound class, this class' job is to strictly control background music.
class BackgroundAudio : public Sound
{
	public:
		BackgroundAudio(const vector<string> audioFilenames);
		~BackgroundAudio();
		void startBackgroundMusic();
	private:	
		static const MySoundEndReceiver* _whenSoundIsFinishedReceiver;
		BackgroundAudio();
		vector<ISoundSource*> _streams;
};

class SoundFXAudio : public Sound
{
	public:
		SoundFXAudio(const string audioFilename);
		~SoundFXAudio();
		void playAudio();
	private:
		SoundFXAudio();
		ISoundSource* _stream;
};

#endif
