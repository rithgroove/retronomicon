#pragma once

#include "component.h"
#include "retronomicon/asset/sound_effect_asset.h"

namespace retronomicon::component {

    /**
     * @brief Component representing a sound effect to be triggered by the audio system.
     */
    class SoundEffectComponent : public Component {
    public:
        SoundEffectComponent() = default;
        explicit SoundEffectComponent(retronomicon::asset::SoundEffectAsset* asset, int loopCount = 0);

        /**
         * @brief Set the sound asset to be played.
         */
        void setAsset(retronomicon::asset::SoundEffectAsset* asset);

        /**
         * @brief Get the sound asset currently attached.
         */
        retronomicon::asset::SoundEffectAsset* getAsset() const;

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
        retronomicon::asset::SoundEffectAsset* m_asset = nullptr;
        int m_loopCount = 0;
        bool m_playRequested = false;
    };

} // namespace retronomicon::lib::audio
