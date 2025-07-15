#pragma once

#include <string>
#include <SDL_mixer.h>
#include "asset.h"

namespace retronomicon::lib::asset {

    /**
     * @brief Represents a short sound effect asset (WAV, OGG, etc.).
     *        Managed using SDL_mixer's Mix_Chunk.
     */
    class SoundEffectAsset : public Asset {
        public:
            explicit SoundEffectAsset(const std::string& path,const std::string& name);
            ~SoundEffectAsset() override;

            /**
             * @brief Get the raw Mix_Chunk pointer
             */
            Mix_Chunk* getRawSound() const;

            /**
             * @brief Textual representation of this asset (for debugging / editor)
             */
            std::string to_string() const override;

        private:
            Mix_Chunk* m_chunk;
    };

}
