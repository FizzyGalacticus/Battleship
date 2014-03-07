//Dustin Dodson & Bucky Frost
//Source file for Sound class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SOUNDS__CPP
#define __BATTLESHIP__SOUNDS__CPP

#include "Sound.h"

/*******************************************/
#include <iostream>
using std::cout;
using std::endl;
/*******************************************/

ISoundEngine * Sound::_engine = createIrrKlangDevice();
vector<ISoundSource*> Sound::_audioStreams;

Sound::~Sound()
{
	_engine->drop();
}

void Sound::pauseAudio()
{
	//Set all sounds to paused
	_engine->setAllSoundsPaused(true);
}

void Sound::unpauseAudio()
{
	//Set all sounds to continue playing
	_engine->setAllSoundsPaused(false);
}

ISoundSource* Sound::initSound(const string audioFilename)
{
	//Start playing audio file
	ISoundSource * stream = _engine->addSoundSourceFromFile(audioFilename.c_str());
	
	//Add new stream to vector of audio streams
	_audioStreams.push_back(stream);
	
	_engine->play2D(stream, true);
	
	return stream;
}

BackgroundAudio::BackgroundAudio(const vector<string> audioFilenames)
{
	//Initialize sound stream
	//_stream = initSound(audioFilename);
	
	for(int i = 0; i < audioFilenames.size(); i++)
		_streams.push_back(initSound(audioFilenames[i]));
}

SoundFXAudio::SoundFXAudio(const string audioFilename)
{
	//Initialize sound stream
	_stream = initSound(audioFilename);
}

BackgroundAudio::~BackgroundAudio()
{
	//Remove stream pointer from base class vector (e.g. we're done with that sound)
	for(int i = 0; i < _streams.size(); i++)
		for(vector<ISoundSource*>::iterator itr = _audioStreams.begin(); itr <= _audioStreams.end(); itr++)
			if(*itr == _streams[i]) _audioStreams.erase(itr);
}

SoundFXAudio::~SoundFXAudio()
{
	//Remove stream pointer from base class vector (e.g. we're done with that sound)
	for(vector<ISoundSource*>::iterator itr = _audioStreams.begin(); itr != _audioStreams.end(); itr++)
		if(*itr == _stream) _audioStreams.erase(itr);
}

#endif
