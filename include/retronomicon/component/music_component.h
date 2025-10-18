#pragma once

#include "retronomicon/core/ecs/component.h"
#include "retronomicon/asset/music_asset.h"

namespace retronomicon::audio {

    /**
     * @brief Component representing a music track to be played by the audio system.
     */
    class MusicComponent : public retronomicon::core::ecs::Component {
    public:
        MusicComponent() = default;
        explicit MusicComponent(retronomicon::asset::MusicAsset* asset, int loopCount = 0);

        /**
         * @brief Set the music asset to be played.
         */
        void setAsset(retronomicon::asset::MusicAsset* asset);

        /**
         * @brief Get the currently assigned music asset.
         */
        retronomicon::asset::MusicAsset* getAsset() const;

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
        retronomicon::asset::MusicAsset* m_asset = nullptr;
        int m_loopCount = 0;
        bool m_playRequested = false;
    };

} // namespace retronomicon::lib::audio
