#include "retronomicon/lib/audio/sound_effect_component.h"

namespace retronomicon::lib::audio {

    SoundEffectComponent::SoundEffectComponent(retronomicon::lib::asset::SoundEffectAsset* asset, int loopCount)
        : m_asset(asset), m_loopCount(loopCount), m_playRequested(false) {}

    void SoundEffectComponent::setAsset(retronomicon::lib::asset::SoundEffectAsset* asset) {
        m_asset = asset;
    }

    retronomicon::lib::asset::SoundEffectAsset* SoundEffectComponent::getAsset() const {
        return m_asset;
    }

    void SoundEffectComponent::setLoopCount(int loopCount) {
        m_loopCount = loopCount;
    }

    int SoundEffectComponent::getLoopCount() const {
        return m_loopCount;
    }

    void SoundEffectComponent::play() {
        m_playRequested = true;
    }

    bool SoundEffectComponent::isPlayRequested() const {
        return m_playRequested;
    }

    void SoundEffectComponent::resetPlayRequest() {
        m_playRequested = false;
    }

}
