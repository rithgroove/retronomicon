#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include "asset.h"

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief Represents a raw binary file loaded into memory.
     * Use for any non-text, structured or opaque file format.
     */
    class BinaryAsset : public Asset {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief Constructor for the binary asset
             *
             * @param path path the file
             * @param name the given name for this font
             */
            explicit BinaryAsset(const std::string& path, const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief default destructor
             */ 
            ~BinaryAsset() override = default;

            /***************************** Getter *****************************/

            /**
             * @brief Returns a const reference to the raw data buffer.
             * 
             * @return vector of unsigned integer that represent the data
             */
            const std::vector<uint8_t>& getData() const { return m_data;}

            /**
             * @brief Returns the size (in bytes) of the loaded binary content.
             * 
             * @return how many bytes of data this file is.
             */
            size_t getSize() const { return m_data.size();}


            /***************************** To String *****************************/
            /**
             * @brief Textual representation of this asset (for debugging / editor)
             *     
             * @return string representation
             */
            std::string to_string() const override;

        private:

            /***************************** Attribute *****************************/
            std::vector<uint8_t> m_data;
    };

}
