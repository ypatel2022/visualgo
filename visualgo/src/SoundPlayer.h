#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class SoundPlayer {
	private:
		sf::SoundBuffer buffer;
		sf::Sound sound;
		unsigned int sampleRate;
		float frequency;
		float amplitude;
		float time;

public:
	SoundPlayer();

	void setPitchMultiplier(int32_t pitchMultiplier);

	void play();

	
};
