#pragma once

#include <string>
#include <SDL_mixer.h>
#include "asset.h"
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief Represents a music asset (typically long background music).
     * Uses SDL_mixer to load and play music from file.
     */
    class MusicAsset : public Asset{

            /***************************** Constructor *****************************/
            
            /**
             * @brief Constructor for the music asset
             *
             * @param path the path to the music
             * @param name the name of the music
             */
            explicit MusicAsset(const std::string& path,const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor for the music asset
             *
             * Releases the asset from memory
             */
            ~MusicAsset() override;

            /***************************** Getter *****************************/

            /**
             * @brief Get the raw Mix_Music pointer
             * 
             *
             *  @return raw music
             */
            Mix_Music* getRawMusic() const { return m_music; }

            /**
             * @brief check if it valid to play
             * 
             * @return boolean of validity
             */
            bool isValid() const{ return m_music != nullptr;}

            /***************************** To String *****************************/

            /**
             * @brief Textual representation of this asset (for debugging / editor)
             *     
             * @return string representation
             */
            std::string to_string() const override;
        private:

            /***************************** Attribute *****************************/
            Mix_Music* m_music;
    };

}
