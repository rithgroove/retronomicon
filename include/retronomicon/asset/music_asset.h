#pragma once

#include "asset.h"
#include <string>
#include <utility>

/**
 * @brief The namespace for assets and loaders.
 */
namespace retronomicon::asset {

    /**
     * @class MusicAsset
     * @brief Abstract base class representing a music asset (e.g. background music).
     * 
     * This class defines a generic interface and shared state for all music assets,
     * regardless of the underlying audio backend (SDL_mixer, OpenAL, FMOD, etc.).
     * 
     * Backend-specific subclasses (e.g. SDLMusicAsset, OpenALMusicAsset)
     * should implement the actual loading, playback, and unloading behavior.
     */
    class MusicAsset : public Asset {
    public:
        /***************************** Constructor *****************************/

        /**
         * @brief Construct a new MusicAsset instance.
         * 
         * @param path The file path to the music asset.
         * @param name The human-readable name of the music asset.
         */
        MusicAsset(std::string path, std::string name)
            : Asset(std::move(path), std::move(name)),
              m_loop(false),
              m_playing(false),
              m_loaded(false) {}
        /***************************** Destructor *****************************/

        /**
         * @brief Virtual destructor.
         */
        ~MusicAsset() override = default;

        /***************************** Virtual Methods *****************************/

        /**
         * @brief Load the music asset from file into memory or stream buffer.
         * 
         * Must be implemented by derived backend-specific classes.
         * 
         * @return true if loading succeeded, false otherwise.
         */
        virtual bool load() = 0;

        /**
         * @brief Unload the music asset and free associated resources.
         * 
         * Must be implemented by derived backend-specific classes.
         */
        virtual void unload() = 0;

        /**
         * @brief Play the music asset.
         * 
         * Must be implemented by derived backend-specific classes.
         * 
         * @param loop Whether the music should loop continuously.
         */
        virtual void play(bool loop = true) = 0;

        /**
         * @brief Stop the music asset if it is currently playing.
         * 
         * Must be implemented by derived backend-specific classes.
         */
        virtual void stop() = 0;

        /***************************** Inline Utility Methods *****************************/

        /**
         * @brief Check if this music asset has been successfully loaded.
         * 
         * @return true if the asset is loaded and ready for playback.
         */
        inline bool isLoaded() const { return m_loaded; }

        /**
         * @brief Check if this music asset is currently playing.
         * 
         * @return true if the music is currently playing.
         */
        inline bool isPlaying() const { return m_playing; }

        /**
         * @brief Check if this music asset is set to loop.
         * 
         * @return true if looping is enabled.
         */
        inline bool isLooping() const { return m_loop; }

        /**
         * @brief Get a human-readable summary of this music asset.
         * 
         * @return string A brief summary including name and path.
         */
        std::string to_string() const override {
            return "[MusicAsset]\n-name=" + m_name + "\n-path=" + m_path +
                   "\n-playing=" + std::string(m_playing ? "true" : "false") +
                   "\n-loop=" + std::string(m_loop ? "true" : "false") +
                   "\n-loaded=" + std::string(m_loaded ? "true" : "false") + "\n";
        }

    protected:
        /***************************** Shared State *****************************/

        bool m_loop;    ///< Whether the music is looping.
        bool m_playing; ///< Whether the music is currently playing.
        bool m_loaded;  ///< Whether the music asset has been loaded.
    };

} // namespace retronomicon::asset
