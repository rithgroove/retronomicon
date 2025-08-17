#include "retronomicon/lib/audio/audio_system.h"
#include "retronomicon/lib/core/entity.h"

namespace retronomicon::lib::audio {

    AudioSystem::AudioSystem() {
        AudioWrapper::init();
    }

    AudioSystem::~AudioSystem() {
        clear();
        AudioWrapper::shutdown();
    }

    void AudioSystem::update(float dt, retronomicon::lib::core::Entity* entity) {

        if (auto* music = entity->getComponent<MusicComponent>()) {
            if (music->isPlayRequested()) {
                m_musicPlayer.play(music->getAsset(), music->getLoopCount());
                music->resetPlayRequest();
            }
        }
        // Check and process sound effect component
        if (auto* sfx = entity->getComponent<SoundEffectComponent>()) {
            if (sfx->isPlayRequested()) {
                m_soundEffectPlayer.play(sfx->getAsset(), sfx->getLoopCount());
                sfx->resetPlayRequest();
            }
        }

        for (Entity* obj : entity->getChilds()) {
            // render logic
             this->update(dt,obj);
        }
    }

    void AudioSystem::clear() {
        // no-op for now, useful if we cache anything later
    }

}
