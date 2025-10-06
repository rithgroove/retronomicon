#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace retronomicon::audio {

    /**
     * @brief Interface for audio playback backends.
     * 
     * Implementations may use SDL_mixer, OpenAL, FMOD, etc.
     * Responsible for initializing, playing, and stopping sounds or music.
     */
    class IAudioPlayer {
    public:
        virtual ~IAudioPlayer() = default;

        /***************************** Initialization *****************************/

        /**
         * @brief Initialize the audio system.
         * 
         * @return true if initialization succeeded, false otherwise.
         */
        virtual bool init() = 0;

        /**
         * @brief Shutdown and clean up audio system.
         */
        virtual void shutdown() = 0;

        /***************************** Music Control *****************************/

        /**
         * @brief Load and play background music.
         * 
         * @param path Path to the music file.
         * @param loop Whether the music should loop.
         */
        virtual void playMusic(const std::string& path, bool loop = true) = 0;

        /**
         * @brief Stop currently playing music.
         */
        virtual void stopMusic() = 0;

        /**
         * @brief Pause or resume currently playing music.
         */
        virtual void setMusicPaused(bool paused) = 0;

        /***************************** Sound Effect Control *****************************/

        /**
         * @brief Load a sound effect from file (cached by name).
         * 
         * @param name Unique identifier for t*
