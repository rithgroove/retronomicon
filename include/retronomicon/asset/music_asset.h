#pragma once

#include "asset.h"
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::asset {

    /**
     * @brief Represents a music asset (typically long background music).
     * Uses SDL_mixer to load and play music from file.
     */
    class MusicAsset : public Asset{
        public:
            /***************************** Constructor *****************************/
            
            /**
             * @brief Constructor for the music asset
             *
             * @param path the path to the music
             * @param name the name of the music
             */
            MusicAsset(const std::string& path,const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor for the music asset
             *
             * Releases the asset from memory
             */
            ~MusicAsset() override;

            /***************************** Getter *****************************/

            /***************************** To String *****************************/

            /**
             * @brief Textual representation of this asset (for debugging / editor)
             *     
             * @return string representation
             */
            std::string to_string() const override {
                return "[MusicAsset]\n-name=" + m_name + "\n-path=" + m_path + "\n";
            }

    };

}
