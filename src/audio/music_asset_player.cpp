#include "retronomicon/lib/audio/music_asset_player.h"

namespace retronomicon::lib::audio {

    MusicAssetPlayer::~MusicAssetPlayer() {
        stop();
    }

    void MusicAssetPlayer::play(retronomicon::lib::asset::MusicAsset* asset, int loopCount) {
        if (!asset || !asset->isValid()) return;

        // Stop previous music if any
        stop();

        if (Mix_PlayMusic(asset->getRawMusic(), loopCount) == -1) {
            // SDL_Log("Failed to play music: %s", Mix_GetError());
            return;
        }

        m_currentAsset = asset;
    }

    void MusicAssetPlayer::stop() {
        if (Mix_PlayingMusic()) {
            Mix_HaltMusic();
        }
        m_currentAsset = nullptr;
    }

    void MusicAssetPlayer::pause() {
        if (Mix_PlayingMusic() && !Mix_PausedMusic()) {
            Mix_PauseMusic();
        }
    }

    void MusicAssetPlayer::resume() {
        if (Mix_PausedMusic()) {
            Mix_ResumeMusic();
        }
    }

    bool MusicAssetPlayer::isPlaying() const {
        return Mix_PlayingMusic() && !Mix_PausedMusic();
    }

    bool MusicAssetPlayer::isPaused() const {
        return Mix_PausedMusic();
    }

    retronomicon::lib::asset::MusicAsset* MusicAssetPlayer::getCurrentAsset() const {
        return m_currentAsset;
    }

} // namesp
