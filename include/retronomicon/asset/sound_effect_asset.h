#pragma once

#include "asset.h"
#include <string>
#include <utility>

/**
 * @brief The namespace for assets and loaders.
 */
namespace retronomicon::asset {

    /**
     * @class SoundEffectAsset
     * @brief Abstract base class representing a short sound effect asset.
     * 
     * This class defines a shared interface and state for all short audio clips.
     * Examples include UI clicks, attack sounds, explosions, or notifications.
     * 
     * Backend-specific subclasses (e.g., SDLSoundEffectAsset, OpenALSoundEffectAsset)
     * implement the concrete loading and playback behavior.
     */
    class SoundEffectAsset : public Asset {
    public:
        /***************************** Constructor / Destructor *****************************/

        /**
         * @brief Construct a new SoundEffectAsset instance.
         * 
         * @param path The file path to the sound effect.
         * @param name The human-readable name of the sound effect.
         */
        SoundEffectAsset(std::string path, std::string name)
            : Asset(std::move(path), std::move(name)),
              m_loaded(false),
              m_playing(false) {}

        /**
         * @brief Virtual destructor.
         */
        ~SoundEffectAsset() override = default;

        /***************************** Virtual Methods *****************************/

        /**
         * @brief Load the sound effect asset from file into memory.
         * 
         * Must be implemented by derived backend-specific classes.
         * 
         * @return true if loading succeeded, false otherwise.
         */
        virtual bool load() = 0;

        /**
         * @brief Unload the sound effect and free associated resources.
         */
        virtual void unload() = 0;

        /**
         * @brief Play the sound effect once (or optionally looped).
         * 
         * Must be implemented by derived backend-specific classes.
         * 
         * @param loop Whether the sound should loop continuously.
         */
        virtual void play(bool loop = false) = 0;

        /**
         * @brief Stop playback of the sound effect if it is playing.
         */
        virtual void stop() = 0;

        /***************************** Inline Utility Methods *****************************/

        /**
         * @brief Check if this sound effect has been loaded successfully.
         * 
         * @return true if the sound effect is loaded.
         */
        inline bool isLoaded() const { return m_loaded; }

        /**
         * @brief Check if this sound effect is currently playing.
         * 
         * @return true if the sound effect is playing.
         */
        inline bool isPlaying() const { return m_playing; }

        /**
         * @brief Get a human-readable summary of this sound effect asset.
         * 
         * @return A formatted string showing its state.
         */
        std::string to_string() const override {
            return "[SoundEffectAsset]\n-name=" + m_name + "\n-path=" + m_path +
                   "\n-playing=" + std::string(m_playing ? "true" : "false") +
                   "\n-loaded=" + std::string(m_loaded ? "true" : "false") + "\n";
        }

    protected:
        /***************************** Shared State *****************************/
        bool m_loaded;   ///< Whether the sound effect is loaded into memory.
        bool m_playing;  ///< Whether the sound effect is currently playing.
    };

} // namespace retronomicon::asset
