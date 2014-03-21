//Dustin Dodson & Bucky Frost
//Source file for Sound class implementation
//CS372 Project 1

#ifndef __BATTLESHIP__SOUNDS__CPP
#define __BATTLESHIP__SOUNDS__CPP

#include "Sound.h"

/*************************************
Static member variables of Sound class
*************************************/
ISoundEngine * Sound::_engine = createIrrKlangDevice();
vector<ISoundSource*> Sound::_audioStreams;
ISound* Sound::_currentPlayingAudioStream = 0;

Sound::~Sound()
{
	if(_audioStreams.size()==0) _engine->drop();
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
	
	return stream;
}

/***********************************************
Static member variables of BackgroundAudio class
***********************************************/
BackgroundAudio::MySoundEndReceiver* BackgroundAudio::_whenSoundIsFinishedReceiver = new MySoundEndReceiver();
int BackgroundAudio::_currentPlayingAudioIndex(0);
int BackgroundAudio::_numberOfTracks(0);
vector<ISoundSource*> BackgroundAudio::_streams;

BackgroundAudio::~BackgroundAudio()
{
	//Remove stream pointer from base class vector (e.g. we're done with that sound)
	for(int i = 0; i < _streams.size(); i++)
		for(vector<ISoundSource*>::iterator itr = _audioStreams.begin(); itr <= _audioStreams.end(); itr++)
			if(*itr == _streams[i]) _audioStreams.erase(itr);
}

void BackgroundAudio::startBackgroundAudio(const int index)
{
	//Start playing first audio track if there is one
	if(_numberOfTracks > 0) _currentPlayingAudioStream = _engine->play2D(_streams[index], false,false,true);
	
	//If we got a valid pointer to ISound object, set stop receiver
	if(_currentPlayingAudioStream)
		_currentPlayingAudioStream->setSoundStopEventReceiver(_whenSoundIsFinishedReceiver);
}


//This function is called any time the current background song has finished playing.
void BackgroundAudio::MySoundEndReceiver::OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData)
{
	//Check to see if we're at the end of the track list
	if(_currentPlayingAudioIndex == (_numberOfTracks-1)) _currentPlayingAudioIndex = 0;
	else _currentPlayingAudioIndex++;
	
	//Start new audio track
	startBackgroundAudio(_currentPlayingAudioIndex);
}

void BackgroundAudio::initBackgroundAudio(const vector<string> & audioFilenames)
{
	_numberOfTracks = audioFilenames.size();
	
	//Initialize _streams
	for(int i = 0; i < audioFilenames.size(); i++)
		_streams.push_back(initSound(audioFilenames[i]));
}

SoundFXAudio::SoundFXAudio(const string audioFilename)
{
	//Initialize sound stream
	_stream = initSound(audioFilename);
}

SoundFXAudio::~SoundFXAudio()
{
	//Remove stream pointer from base class vector (e.g. we're done with that sound)
	for(vector<ISoundSource*>::iterator itr = _audioStreams.begin(); itr != _audioStreams.end(); itr++)
		if(*itr == _stream) _audioStreams.erase(itr);
}

void SoundFXAudio::playAudio()
{
	_engine->play2D(_stream, false);
}

#endif
