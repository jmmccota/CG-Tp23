#pragma once
#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <vector>

class FMOD_Audio
{
protected:
	FMOD::Sound *sound;
	std::vector<FMOD::Channel *> channel;
public:
	FMOD_Audio(FMOD::System *system, char *file, bool loop);
	FMOD_Audio();
	~FMOD_Audio();

	
	//Getters
	FMOD::Sound *getSound();
	
	//Reset Channels
	void resetAudio();

	//Play Once
	void playStreamAudio(FMOD::System *system, char *file, bool loop);

	//Save in memory and play
	void playMemoryAudio(FMOD::System *system);
	
	//Save in memory and play, give more channel to use
	void playMemoryAudio(FMOD::System *system, bool giveMoreChannel);
	
	//Stop som
	void stopAudio();
	
	//Set volume 0 to 100
	void setVolume(float volume);

};

