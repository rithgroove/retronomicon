#include "retronomicon/lib/audio/music_component.h"

namespace retronomicon::lib::audio {

    MusicComponent::MusicComponent(const std::string& filepath, float volume, bool loop)
        : m_filePath(filepath), m_volume(volume), m_loop(loop) {}

    void MusicComponent::setFilePath(const std::string& path) {
        m_filePath = path;
    }

    void MusicComponent::play() {
        m_playing = true;
    }

    void MusicComponent::stop() {
        m_playing = false;
    }

    bool MusicComponent::isPlaying() const {
        return m_playing;
    }


    void MusicComponent::setVolume(float vol) {
        m_volume = vol;
    }

    void MusicComponent::setLoop(bool loop) {
        m_loop = loop;
    }

    const std::string& MusicComponent::getFilePath() const {
        return m_filePath;
    }

    float MusicComponent::getVolume() const {
        return m_volume;
    }

    bool MusicComponent::isLooping() const {
        return m_loop;
    }

} // namespace retronomicon::lib::audio
