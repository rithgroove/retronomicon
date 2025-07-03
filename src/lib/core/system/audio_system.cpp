#include "retronomicon/lib/core/system/audio_system.h"
#include <iostream> // placeholder

namespace retronomicon::lib::core::system {

void AudioSystem::play_sfx(const std::string& sound_id, float volume, bool spatial) {
    std::cout << "[SFX] Play: " << sound_id << " vol=" << volume
              << (spatial ? " (spatial)\n" : "\n");
    // TODO: backend: play sound at location if spatial
}

void AudioSystem::update(float dt) {
    // Might handle queued sounds later
}

}
