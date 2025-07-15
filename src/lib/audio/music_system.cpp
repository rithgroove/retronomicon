#include "retronomicon/lib/audio/music_system.h"
#include <iostream>

namespace retronomicon::lib::audio {

    MusicSystem::MusicSystem(retronomicon::lib::asset::AssetManager* assetManager)
        : m_assetManager(assetManager) {}

    void MusicSystem::update(float dt, vector<retronomicon::lib::core::GameObject*>& objects) {
        // This would normally iterate through ECS entities
        // For now, music is treated as global
    }

    void MusicSystem::playMusic(const MusicComponent& musicComp) {
        if (musicComp.getFilePath() == m_currentMusicPath) {
            return; // Already playing this music
        }

        auto musicAsset = m_assetManager->loadMusic(musicComp.getFilePath(), musicComp.getFilePath());
        if (!musicAsset || !musicAsset->isValid()) {
            std::cerr << "Failed to load or validate music asset: " << musicComp.getFilePath() << std::endl;
            return;
        }

        Mix_VolumeMusic(static_cast<int>(musicComp.getVolume() * MIX_MAX_VOLUME));

        int loopFlag = musicComp.isLooping() ? -1 : 1;
        if (Mix_PlayMusic(musicAsset->getRawMusic(), loopFlag) == -1) {
            std::cerr << "Error playing music: " << Mix_GetError() << std::endl;
        } else {
            m_currentMusicPath = musicComp.getFilePath();
        }
    }

    void MusicSystem::stopMusic() {
        Mix_HaltMusic();
        m_currentMusicPath = "";
    }

} // namespace retronomicon::lib::audio
