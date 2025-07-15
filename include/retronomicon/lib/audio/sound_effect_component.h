#pragma once

#include <string>
#include <SDL_mixer.h>

#include "retronomicon/lib/core/component.h"

namespace retronomicon::lib::audio {

    /**
     * @brief A component that represents a sound effect in the game world.
     */
    class SoundEffectComponent : public retronomicon::lib::core::Component {
    public:
        /**
         * @brief Constructor
         * 
         * @param path Path to the sound file.
         * @param loop Whether the sound should loop when played.
         */
        SoundEffectComponent(const std::string& path, bool loop = false);

        /**
         * @brief Destructor
         */
        ~SoundEffectComponent();

        /**
         * @brief Get the sound effect object
         */
        Mix_Chunk* getSound() const;

        /**
         * @brief Get the path of the loaded sound file.
         */
        const std::string& getPath() const;

        /**
         * @brief Should this sound loop?
         */
        bool shouldLoop() const;

        /**
         * @brief Is the sound asset valid (i.e., successfully loaded)?
         */
        bool isValid() const;

    private:
        std::string m_path;
        Mix_Chunk* m_sound = nullptr;
        bool m_loop = false;
    };

} // namespace retronomicon::lib::audio
