#pragma once

#include <string>
#include "retronomicon/lib/asset/asset.h"
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief Represents a text-based asset loaded from file (e.g., .txt, .json).
     */
    class TextAsset : public Asset {
        public:
            /***************************** Constructor *****************************/
            
            /**
             * @brief Constructor for the text file asset
             *
             * @param path the path to the text file
             * @param name the name of the text file
             */
            explicit TextAsset(const std::string& path,const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief Destructor for the music asset
             *
             * Releases the asset from memory
             */
            ~TextAsset() override = default;

            /***************************** Getter *****************************/

            /**
             * @brief Returns the full contents of the file as a string.
             * 
             * @return the content
             */
            const std::string& getContent() const{return m_content;}

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const override;

        private:
            /***************************** Attribute *****************************/
            std::string m_content;
    };

}
