//Dustin Dodson & Bucky Frost
//Source file for Sound class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SOUNDS__CPP
#define __BATTLESHIP__SOUNDS__CPP

#include "Sound.h"

ISoundEngine * Sound::_engine = createIrrKlangDevice();
vector<ISoundSource*> Sound::_audioStreams;

Sound::Sound(const string audioFilename)
{
	//Start playing audio file
	ISoundSource * stream = _engine->addSoundSourceFromFile(audioFilename.c_str());
	
	//Add new stream to vector of audio streams
	_audioStreams.push_back(stream);
	
	_engine->play2D(stream, true);
}

Sound::~Sound()
{
	_engine->drop();
}

void Sound::pauseAudio()
{
	_engine->setAllSoundsPaused(true);
}

void Sound::unpauseAudio()
{
	_engine->setAllSoundsPaused(false);
}

#endif