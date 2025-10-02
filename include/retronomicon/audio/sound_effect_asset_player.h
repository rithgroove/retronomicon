#pragma once

#include "retronomicon/lib/asset/sound_effect_asset.h"
#include <SDL_mixer.h>

namespace retronomicon::lib::audio {

    using retronomicon::lib::asset::SoundEffectAsset;
    /**
     * @brief A simple player class to handle playback of sound effects.
     */
    class SoundEffectAssetPlayer {
    public:
        SoundEffectAssetPlayer();
        ~SoundEffectAssetPlayer();

        /**
         * @brief Play a sound effect.
         * 
         * @param soundAsset The sound effect asset to play.
         * @param loopCount Number of times to loop (0 = play once, -1 = loop forever).
         */
        void play(SoundEffectAsset* soundAsset, int loopCount = 0);
    };

} // namespace retronomicon::lib::audio
