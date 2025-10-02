#pragma once

#include <SDL_mixer.h>
#include "retronomicon/lib/asset/music_asset.h"

namespace retronomicon::lib::audio {

    /**
     * @brief A class responsible for playing MusicAsset objects using SDL_mixer.
     */
    class MusicAssetPlayer {
    public:
        MusicAssetPlayer() = default;
        ~MusicAssetPlayer();

        /**
         * @brief Load and play a MusicAsset.
         * 
         * @param asset The music asset to play.
         * @param loopCount Number of times to loop. -1 for infinite looping.
         */
        void play(retronomicon::lib::asset::MusicAsset* asset, int loopCount = -1);

        /**
         * @brief Stop currently playing music.
         */
        void stop();

        /**
         * @brief Pause the currently playing music.
         */
        void pause();

        /**
         * @brief Resume paused music.
         */
        void resume();

        /**
         * @brief Check if music is playing.
         */
        bool isPlaying() const;

        /**
         * @brief Check if music is paused.
         */
        bool isPaused() const;

        /**
         * @brief Get the currently active asset.
         */
        retronomicon::lib::asset::MusicAsset* getCurrentAsset() const;

    private:
        retronomicon::lib::asset::MusicAsset* m_currentAsset = nullptr;
    };

} // namespace retronomicon::lib::audio
