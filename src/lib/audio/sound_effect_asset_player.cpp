#include "retronomicon/lib/audio/sound_effect_asset_player.h"
#include <iostream>

namespace retronomicon::lib::audio {

    SoundEffectAssetPlayer::SoundEffectAssetPlayer() {}

    SoundEffectAssetPlayer::~SoundEffectAssetPlayer() {
        // No persistent state or cleanup needed
    }

    void SoundEffectAssetPlayer::play(SoundEffectAsset* soundAsset, int loopCount) {
        if (!soundAsset || !soundAsset->getRawSound()) {
            std::cerr << "SoundEffectAsset is null or not loaded correctly." << std::endl;
            return;
        }

        // Play on the first free channel (-1), looping as specified
        if (Mix_PlayChannel(-1, soundAsset->getRawSound(), loopCount) == -1) {
            std::cerr << "Failed to play sound effect: " << Mix_GetError() << std::endl;
        }
    }

}
