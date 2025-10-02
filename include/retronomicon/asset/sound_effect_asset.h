#pragma once

#include <string>
#include "asset.h"
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::asset {

    /**
     * @brief Represents a short sound effect asset (WAV, OGG, etc.).
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


            /***************************** To String *****************************/
           /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const override {
                return "[SoundEffectAsset]\n-name=" + m_name + "\n-path=" + m_path + "\n";
            }

    };

}
