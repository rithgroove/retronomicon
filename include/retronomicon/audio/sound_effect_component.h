#pragma once

#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/asset/sound_effect_asset.h"

namespace retronomicon::lib::audio {

    /**
     * @brief Component representing a sound effect to be triggered by the audio system.
     */
    class SoundEffectComponent : public retronomicon::lib::core::Component {
    public:
        SoundEffectComponent() = default;
        explicit SoundEffectComponent(retronomicon::lib::asset::SoundEffectAsset* asset, int loopCount = 0);

        /**
         * @brief Set the sound asset to be played.
         */
        void setAsset(retronomicon::lib::asset::SoundEffectAsset* asset);

        /**
         * @brief Get the sound asset currently attached.
         */
        retronomicon::lib::asset::SoundEffectAsset* getAsset() const;

        /**
         * @brief Set how many times the sound should loop.
         */
        void setLoopCount(int loopCount);

        /**
         * @brief Get the loop count.
         */
        int getLoopCount() const;

        /**
         * @brief Mark the sound effect to be played on the next update.
         */
        void play();

        /**
         * @brief Check if play was requested.
         */
        bool isPlayRequested() const;

        /**
         * @brief Clear play request flag.
         */
        void resetPlayRequest();

    private:
        retronomicon::lib::asset::SoundEffectAsset* m_asset = nullptr;
        int m_loopCount = 0;
        bool m_playRequested = false;
    };

} // namespace retronomicon::lib::audio
