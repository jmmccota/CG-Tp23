#include "FMOD_Audio.hpp"


FMOD_Audio::FMOD_Audio(FMOD::System *system, char *file, bool loop)
{
	FMOD::Channel* firstChannel;
	channel.push_back(firstChannel);

	system->createSound(file, FMOD_DEFAULT, 0, &sound);
	if (loop) {
		sound->setMode(FMOD_LOOP_NORMAL);
	}

	bool isPlaying;

	system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel[0]);
	system->update();
}

FMOD_Audio::FMOD_Audio()
{
}

FMOD::Sound * FMOD_Audio::getSound()
{
	return this->sound;
}

void FMOD_Audio::resetAudio()
{
	sound->release();
	for (int i = 0; i < channel.size(); i++) {
		channel[i] = 0;
	}
}

void FMOD_Audio::playStreamAudio(FMOD::System *system, char *file, bool loop)
{
	FMOD::Channel* streamChannel;
	system->createStream(file, FMOD_HARDWARE, 0, &sound);
	system->playSound(FMOD_CHANNEL_FREE, sound, false, &streamChannel);

	if (loop) {
		this->sound->setMode(FMOD_LOOP_NORMAL);
	}

}

void FMOD_Audio::playMemoryAudio(FMOD::System *system)
{
	bool isPaused = false;
	channel[0]->getPaused(&isPaused);

	if (!isPaused) {
		system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel[0]);
	}
	else {
		channel[0]->setPaused(false);
	}
}

void FMOD_Audio::playMemoryAudio(FMOD::System * system, bool giveMoreChannel)
{
	FMOD::Channel *freeChannel = 0;
	channel[0]->setPaused(false);

	if (giveMoreChannel) {
		for (int i = 0; i < channel.size(); i++) {
		
			bool isPlaying = false;
			channel[i]->isPlaying(&isPlaying);
			if (!isPlaying) {
				freeChannel = channel[i];
				break;
			}
		}
		if (freeChannel == 0) {
			system->playSound(FMOD_CHANNEL_FREE, sound, false, &freeChannel);
			channel.push_back(freeChannel);
		}
		else {
			system->playSound(FMOD_CHANNEL_REUSE, sound, false, &freeChannel);
		}
	}
	else {
		playMemoryAudio(system);
	}
}

void FMOD_Audio::stopAudio()
{
	for (int i = 0; i < channel.size(); i++) {
		channel[i]->setPaused(true);
	}
}

void FMOD_Audio::setVolume(float volume)
{
	if (volume >= 0 && volume <= 100) {
		for (int i = 0; i < channel.size(); i++) {
			channel[i]->setVolume(volume / 100);
		}
	}
}

FMOD_Audio::~FMOD_Audio()
{
	resetAudio();
}
