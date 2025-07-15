#include "retronomicon/lib/audio/sound_effect_component.h"
#include <iostream>

namespace retronomicon::lib::audio {

    SoundEffectComponent::SoundEffectComponent(const std::string& path, bool loop)
        : m_path(path), m_loop(loop)
    {
        m_sound = Mix_LoadWAV(m_path.c_str());
        if (!m_sound) {
            std::cerr << "Failed to load sound effect: " << m_path
                      << "\nReason: " << Mix_GetError() << std::endl;
        }
    }

    SoundEffectComponent::~SoundEffectComponent() {
        if (m_sound) {
            Mix_FreeChunk(m_sound);
            m_sound = nullptr;
        }
    }

    Mix_Chunk* SoundEffectComponent::getSound() const {
        return m_sound;
    }

    const std::string& SoundEffectComponent::getPath() const {
        return m_path;
    }

    bool SoundEffectComponent::shouldLoop() const {
        return m_loop;
    }

    bool SoundEffectComponent::isValid() const {
        return m_sound != nullptr;
    }

}
