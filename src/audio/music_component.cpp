#include "retronomicon/lib/audio/music_component.h"

namespace retronomicon::lib::audio {

    MusicComponent::MusicComponent(retronomicon::lib::asset::MusicAsset* asset, int loopCount)
        : m_asset(asset), m_loopCount(loopCount), m_playRequested(false) {}

    void MusicComponent::setAsset(retronomicon::lib::asset::MusicAsset* asset) {
        m_asset = asset;
    }

    retronomicon::lib::asset::MusicAsset* MusicComponent::getAsset() const {
        return m_asset;
    }

    void MusicComponent::setLoopCount(int loopCount) {
        m_loopCount = loopCount;
    }

    int MusicComponent::getLoopCount() const {
        return m_loopCount;
    }

    void MusicComponent::play() {
        m_playRequested = true;
    }

    bool MusicComponent::isPlayRequested() const {
        return m_playRequested;
    }

    void MusicComponent::resetPlayRequest() {
        m_playRequested = false;
    }

}
