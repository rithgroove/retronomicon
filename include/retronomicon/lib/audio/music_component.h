#pragma once

#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/asset/music_asset.h"

namespace retronomicon::lib::audio {

    /**
     * @brief Component representing a music track to be played by the audio system.
     */
    class MusicComponent : public retronomicon::lib::core::Component {
    public:
        MusicComponent() = default;
        explicit MusicComponent(retronomicon::lib::asset::MusicAsset* asset, int loopCount = 0);

        /**
         * @brief Set the music asset to be played.
         */
        void setAsset(retronomicon::lib::asset::MusicAsset* asset);

        /**
         * @brief Get the currently assigned music asset.
         */
        retronomicon::lib::asset::MusicAsset* getAsset() const;

        /**
         * @brief Set how many times the music should loop.
         */
        void setLoopCount(int loopCount);

        /**
         * @brief Get the loop count.
         */
        int getLoopCount() const;

        /**
         * @brief Mark the music to be played on next update cycle.
         */
        void play();

        /**
         * @brief Check if play was requested.
         */
        bool isPlayRequested() const;

        /**
         * @brief Clear play request.
         */
        void resetPlayRequest();

    private:
        retronomicon::lib::asset::MusicAsset* m_asset = nullptr;
        int m_loopCount = 0;
        bool m_playRequested = false;
    };

} // namespace retronomicon::lib::audio
