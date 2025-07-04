#pragma once

#include <string>
#include <optional>

namespace retronomicon::lib::audio {

class AudioWrapper {
public:
    static void init();  // Call this during engine startup
    static void shutdown(); // Cleanup at shutdown

    static void play_music(const std::string& track_id, bool loop = true);
    static void stop_music();
    static void fade_music_to(const std::string& track_id, float duration);

    static void play_sfx(const std::string& sound_id, float volume = 1.0f, std::optional<float> position = std::nullopt);

private:
    static bool initialized_;
};

}