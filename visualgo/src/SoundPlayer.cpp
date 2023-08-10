#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() : sampleRate(44100), frequency(440.0), amplitude(0.5), time(0.0) {
    buffer.loadFromSamples(nullptr, 0, 1, sampleRate);
    sound.setBuffer(buffer);
}

void SoundPlayer :: setPitchMultiplier(int32_t pitchMultiplier) {
  
    float octaveFactor = std::pow(2.0f, static_cast<float>(pitchMultiplier) / 12.0f);

    frequency = 440.0 * octaveFactor;
    std:: cout << pitchMultiplier << " " << frequency << std :: endl;
}


void SoundPlayer::play() {
    // Generate the sine wave samples
    std::vector<sf::Int16> samples;
    for (int i = 0; i < sampleRate * 0.1; ++i) { // Play for 0.1 seconds
        float fadeMultiplier = std::min(1.0f, static_cast<float>(i) / (sampleRate * 0.01f)); // Fade-in effect
        fadeMultiplier = std::min(fadeMultiplier, static_cast<float>(sampleRate * 0.1 - i) / (sampleRate * 0.01f)); // Fade-out effect

        float value = amplitude * fadeMultiplier * std::sin(2.0f * 3.14159f * frequency * time);
        samples.push_back(static_cast<sf::Int16>(value * 32767));
        time += 1.0f / sampleRate;
    }

    if (!samples.empty()) {
        // Load the generated samples into the buffer
        buffer.loadFromSamples(&samples[0], samples.size(), 1, sampleRate);

        // Play the sound
        sound.play();
    }
}