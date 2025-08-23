#pragma once

#include <string>
#include <SDL_mixer.h>
#include "asset.h"
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief Represents a short sound effect asset (WAV, OGG, etc.).
     *        Managed using SDL_mixer's Mix_Chunk.
     */
    class SoundEffectAsset : public Asset {
        public:
            /***************************** Constructor *****************************/
            
            /**
             * @brief Constructor for the sfx asset
             *
             * @param path the path to the sfx
             * @param name the name of the sfx
             */
            SoundEffectAsset(const std::string& path,const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor for the sfx asset
             *
             * Releases the asset from memory
             */
            ~SoundEffectAsset() override;

            /***************************** Getter *****************************/

            /**
             * @brief Get the raw Mix_Chunk pointer
             */
            Mix_Chunk* getRawSound() const { return m_chunk; }

            /***************************** To String *****************************/
           /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const override;

        private:
            /***************************** Attribute *****************************/
            Mix_Chunk* m_chunk;
    };

}
