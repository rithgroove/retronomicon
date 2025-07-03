#include "retronomicon/lib/core/system/music_system.h"
#include <iostream> // replace with actual audio backend later

namespace retronomicon::lib::core::system {

void MusicSystem::play(const std::string& track_id, bool loop) {
    std::cout << "[Music] Playing: " << track_id << " (loop=" << loop << ")\n";
    current_track_ = track_id;
    loop_ = loop;
    // TODO: hook to backend: play(track_id)
}

void MusicSystem::stop() {
    std::cout << "[Music] Stopped.\n";
    current_track_.clear();
    // TODO: backend: stop()
}

void MusicSystem::fade_to(const std::string& new_track_id, float duration) {
    std::cout << "[Music] Fading to: " << new_track_id << " over " << duration << "s\n";
    next_track_ = new_track_id;
    fade_duration_ = duration;
    fade_timer_ = 0.0f;
    fading_ = true;
    // TODO: backend: start fade
}

void MusicSystem::update(float dt) {
    if (fading_) {
        fade_timer_ += dt;
        float t = fade_timer_ / fade_duration_;
        if (t >= 1.0f) {
            fading_ = false;
            play(next_track_, loop_);
        } else {
            float new_volume = (1.0f - t) * current_volume_;
            // TODO: backend: set volume
        }
    }
}

void MusicSystem::set_volume(float volume) {
    current_volume_ = volume;
    // TODO: backend: set volume
}

float MusicSystem::get_volume() const {
    return current_volume_;
}

}
