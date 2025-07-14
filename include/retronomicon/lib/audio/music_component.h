#pragma once

#include <string>
#include "retronomicon/lib/core/component.h"

namespace retronomicon::lib::audio {

    class MusicComponent : public retronomicon::lib::core::Component {
    public:
        MusicComponent(const std::string& filepath, float volume = 1.0f, bool loop = false);

        // Setters
        void setFilePath(const std::string& path);
        void setVolume(float vol);
        void setLoop(bool loop);

        // Getters
        const std::string& getFilePath() const;
        float getVolume() const;
        bool isLooping() const;

        void play();
        void stop();
        bool isPlaying() const;
    private:
        std::string m_filePath;
        float m_volume = 1.0f;
        bool m_loop = false;
        bool m_playing = false;
    };

} // namespace retronomicon::lib::audio
