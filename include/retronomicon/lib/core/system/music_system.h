
#pragma once

#include <string>
#include "retronomicon/lib/core/system.h"

using namespace retronomicon::lib::core;
namespace retronomicon::lib::core::system {

class MusicSystem {
public:
    void play(const std::string& track_id, bool loop = true);
    void stop();
    void fade_to(const std::string& new_track_id, float duration);
    void update(float dt);

    void set_volume(float volume);
    float get_volume() const;

private:
    std::string current_track_;
    std::string next_track_;
    float current_volume_ = 1.0f;
    float fade_timer_ = 0.0f;
    float fade_duration_ = 0.0f;
    bool fading_ = false;
    bool loop_ = true;
};

}
