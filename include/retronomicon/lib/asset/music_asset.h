#pragma once

#include <string>
#include <SDL_mixer.h>
#include "asset.h"

namespace retronomicon::lib::asset {

    /**
     * @brief Represents a music asset (typically long background music).
     * Uses SDL_mixer to load and play music from file.
     */
    class MusicAsset : public Asset {
        public:
            explicit MusicAsset(const std::string& path);
            ~MusicAsset() override;

            /**
             * @brief Get the raw Mix_Music pointer
             */
            Mix_Music* getRawMusic() const;

            /**
             * @brief Textual representation of this asset (for debugging / editor)
             */
            std::string to_string() const override;

        private:
            Mix_Music* m_music;
    };

}
