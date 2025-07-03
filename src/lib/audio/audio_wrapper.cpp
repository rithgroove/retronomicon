#include "retronomicon/lib/audio/audio_wrapper.h"
#include <iostream>

namespace retronomicon::lib::audio {

bool AudioWrapper::initialized_ = false;

void AudioWrapper::init() {
    if (!initialized_) {
        std::cout << "[AudioWrapper] Initialized.\n";
        // TODO: backend init (e.g., Mix_OpenAudio)
        initialized_ = true;
    }
}

void AudioWrapper::shutdown() {
    if (initialized_) {
        std::cout << "[AudioWrapper] Shutdown.\n";
        // TODO: backend cleanup (e.g., Mix_CloseAudio)
        initialized_ = false;
    }
}

void AudioWrapper::play_music(const std::string& track_id, bool loop) {
    std::cout << "[AudioWrapper] Playing music: " << track_id
              << (loop ? " (loop)" : "") << "\n";
    // TODO: backend music play
}

void AudioWrapper::stop_music() {
    std::cout << "[AudioWrapper] Stopping music.\n";
    // TODO: backend music stop
}

void AudioWrapper::fade_music_to(const std::string& track_id, float duration) {
    std::cout << "[AudioWrapper] Fading to music: " << track_id
              << " over " << duration << " seconds\n";
    // TODO: backend fade logic
}

void AudioWrapper::play_sfx(const std::string& sound_id, float volume, std::optional<float> position) {
    std::cout << "[AudioWrapper] Playing SFX: " << sound_id
              << " (vol=" << volume << ")"
              << (position ? " [spatial]" : "") << "\n";
    // TODO: backend sfx play (positional if available)
}

}
