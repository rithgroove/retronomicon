#pragma once

#include <string>
#include "retronomicon/lib/core/system.h"

using namespace retronomicon::lib::core;
namespace retronomicon::lib::core::system {

class AudioSystem {
public:
    void play_sfx(const std::string& sound_id, float volume = 1.0f, bool spatial = false);
    void update(float dt);
};

}
