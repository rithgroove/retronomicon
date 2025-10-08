#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace retronomicon::audio {
    /**
     * @brief Minimal 3D vector struct for positional audio.
     */
    struct Vec3 {
        float x{0.0f};
        float y{0.0f};
        float z{0.0f};
    };


    /**
     * @brief Abstract interface for audio playback systems.
     * 
     * Provides unified access for music and sound effects, allowing
     * flexible backends (OpenAL, SDL_mixer, FMOD, etc.)
     */
    class IAudioPlayer {
    public:
        virtual ~IAudioPlayer() = default;

        /***************************** Initialization *****************************/

        /**
         * @brief Initialize the audio system.
         * @return true if initialization succeeded, false otherwise.
         */
        virtual bool init() = 0;

        /**
         * @brief Shutdown and clean up audio system resources.
         */
        virtual void shutdown() = 0;

        /***************************** Global Control *****************************/

        /**
         * @brief Set master volume (affects both music and sound effects).
         * @param volume Volume between 0.0f and 1.0f.
         */
        virtual void setMasterVolume(float volume) = 0;

        /**
         * @brief Get current master volume.
         */
        virtual float getMasterVolume() const = 0;

        /**
         * @brief Update any streaming buffers, fades, etc.
         * Should be called once per frame.
         */
        virtual void update() = 0;

        /***************************** Music Control *****************************/

        /**
         * @brief Load and play background music.
         * @param path Path to the music file.
         * @param loop Whether the music should loop.
         * @param fadeInMs Fade-in time in milliseconds (optional).
         */
        virtual void playMusic(const std::string& path, bool loop = true, int fadeInMs = 0) = 0;

        /**
         * @brief Stop currently playing music.
         * @param fadeOutMs Optional fade-out duration in milliseconds.
         */
        virtual void stopMusic(int fadeOutMs = 0) = 0;

        /**
         * @brief Pause or resume currently playing music.
         */
        virtual void setMusicPaused(bool paused) = 0;

        /**
         * @brief Check if music is currently playing.
         */
        virtual bool isMusicPlaying() const = 0;

        /**
         * @brief Set music volume.
         * @param volume Volume between 0.0f and 1.0f.
         */
        virtual void setMusicVolume(float volume) = 0;

        /**
         * @brief Get current music volume.
         */
        virtual float getMusicVolume() const = 0;

        /***************************** Sound Effect Control *****************************/

        /**
         * @brief Load a sound effect (cached by name).
         * @param name Unique identifier.
         * @param path Path to sound file.
         * @return true if loaded successfully.
         */
        virtual bool loadSoundEffect(const std::string& name, const std::string& path) = 0;

        /**
         * @brief Play a previously loaded sound effect.
         * @param name Cached identifier.
         * @param volume Volume between 0.0f and 1.0f (applied on top of SFX volume).
         * @param loop Whether to loop the sound.
         */
        virtual void playSoundEffect(const std::string& name, float volume = 1.0f, bool loop = false) = 0;

        /**
         * @brief Stop all sound effects or a specific one by name.
         * @param name Optional; if empty, stops all sounds.
         */
        virtual void stopSoundEffect(const std::string& name = "") = 0;

        /**
         * @brief Set the volume of all sound effects globally.
         * @param volume Volume between 0.0f and 1.0f.
         */
        virtual void setSfxVolume(float volume) = 0;

        /**
         * @brief Get global sound effect volume.
         */
        virtual float getSfxVolume() const = 0;

        /**
         * @brief Unload a sound effect from cache.
         */
        virtual void unloadSoundEffect(const std::string& name) = 0;

        /**
         * @brief Clear all loaded sound effects.
         */
        virtual void clearSoundCache() = 0;

        /***************************** 3D Positional Audio *****************************/

        /**
         * @brief Set listener position (optional for 3D backends).
         */
        virtual void setListenerPosition(const Vec3& pos) {}

        /**
         * @brief Play a positional sound effect in 3D space (optional).
         */
        virtual void playSoundEffect3D(const std::string& name, const Vec3& pos, float volume = 1.0f, bool loop = false) {}
    };

} // namespace retronomicon::audio
