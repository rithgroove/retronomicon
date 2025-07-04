#pragma once

#include <string>

namespace retronomicon::lib::core::system {

class AudioSystem {
public:
    void play_sfx(const std::string& sound_id, float volume = 1.0f, bool spatial = false);
    void update(float dt);
};

}
