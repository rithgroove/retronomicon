#include "retronomicon/lib/audio/music_asset_player.h"
#include <iostream>

namespace retronomicon::lib::audio {

    MusicAssetPlayer::MusicAssetPlayer() {}

    MusicAssetPlayer::~MusicAssetPlayer() {
        stop();
    }

    void MusicAssetPlayer::load(MusicAsset* musicAsset) {
        m_musicAsset = musicAsset;
    }

    void MusicAssetPlayer::play(int loopCount) {
        if (m_musicAsset && m_musicAsset->isValid()) {
            if (Mix_PlayMusic(m_musicAsset->getRawMusic(), loopCount) == -1) {
                std::cerr << "Failed to play music: " << Mix_GetError() << std::endl;
            }
        } else {
            std::cerr << "MusicAsset not valid or not loaded." << std::endl;
        }
    }

    void MusicAssetPlayer::pause() {
        if (Mix_PlayingMusic()) {
            Mix_PauseMusic();
        }
    }

    void MusicAssetPlayer::resume() {
        if (Mix_PausedMusic()) {
            Mix_ResumeMusic();
        }
    }

    void MusicAssetPlayer::stop() {
        if (Mix_PlayingMusic()) {
            Mix_HaltMusic();
        }
    }

    bool MusicAssetPlayer::isPlaying() const {
        return Mix_PlayingMusic() != 0;
    }

    bool MusicAssetPlayer::isPaused() const {
        return Mix_PausedMusic() != 0;
    }

}
