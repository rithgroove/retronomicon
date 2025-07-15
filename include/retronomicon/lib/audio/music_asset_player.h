#pragma once

#include "retronomicon/lib/asset/music_asset.h"
#include <SDL_mixer.h>

namespace retronomicon::lib::audio {
    using retronomicon::lib::asset::MusicAsset;
    /**
     * @brief A simple music playback controller for MusicAsset.
     */
    class MusicAssetPlayer {
    public:
        /**
         * @brief Construct a new MusicAssetPlayer.
         */
        MusicAssetPlayer();

        /**
         * @brief Destructor — stops and frees music.
         */
        ~MusicAssetPlayer();

        /**
         * @brief Load a music asset and prepare for playback.
         */
        void load(MusicAsset* musicAsset);

        /**
         * @brief Play the loaded music asset.
         * @param loopCount Number of times to loop (-1 for infinite).
         */
        void play(int loopCount = -1);

        /**
         * @brief Pause the currently playing music.
         */
        void pause();

        /**
         * @brief Resume the paused music.
         */
        void resume();

        /**
         * @brief Stop the music playback.
         */
        void stop();

        /**
         * @brief Check if any music is currently playing.
         */
        bool isPlaying() const;

        /**
         * @brief Check if music is currently paused.
         */
        bool isPaused() const;

    private:
        MusicAsset* m_musicAsset = nullptr;
    };

} // namespace retronomicon::lib::audio
