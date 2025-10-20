#include "retronomicon/system/audio_system.h"
#include "retronomicon/component/music_component.h"
#include "retronomicon/component/sound_effect_component.h"

#include <sstream>

namespace retronomicon::system {
    using retronomicon::component::MusicComponent;
    using retronomicon::component::SoundEffectComponent;
    
    /***************************** Constructor *****************************/
    AudioSystem::AudioSystem(std::shared_ptr<IAudioPlayer> audioPlayer)
        : m_audioPlayer(std::move(audioPlayer)) {}

    /***************************** To String *****************************/
    std::string AudioSystem::to_string() const {
        std::ostringstream oss;
        oss << "[Audio System]\n";
        return oss.str();
    }

    /***************************** Override Method *****************************/
    void AudioSystem::update(float dt, std::weak_ptr<Entity> weakEntity) {
        if (!m_audioPlayer) return;

        if (auto entity = weakEntity.lock()) {

            // Update the audio backend (streaming buffers, fades, etc.)
            m_audioPlayer->update();

            /***************************** Music Component *****************************/
            if (auto musicComp = entity->getComponent<MusicComponent>()) {
                auto asset = musicComp->getAsset();
                if (asset && musicComp->isPlayRequested()) {
                    // Play music asset
                    m_audioPlayer->playMusic(asset->getPath(), musicComp->getLoopCount() != 0);
                    musicComp->resetPlayRequest();
                }
            }

            /***************************** Sound Effect Component *****************************/
            if (auto sfxComp = entity->getComponent<SoundEffectComponent>()) {
                auto asset = sfxComp->getAsset();
                if (asset && sfxComp->isPlayRequested()) {
                    // Cache and play SFX
                    const std::string& sfxName = asset->getName();
                    const std::string& sfxPath = asset->getPath();

                    // Lazy-load if not already cached
                    m_audioPlayer->loadSoundEffect(sfxName, sfxPath);

                    // Loop if loopCount != 0
                    bool loop = sfxComp->getLoopCount() != 0;
                    m_audioPlayer->playSoundEffect(sfxName, 1.0f, loop);
                    sfxComp->resetPlayRequest();
                }
            }

            // Recursively update children
            for (auto& child : entity->getChildren()) {
                update(dt, child);
            }
        }
    }

} // namespace retronomicon::audio
