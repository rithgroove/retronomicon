#pragma once

#include <string>
#include <vector>
#include "asset.h"

namespace retronomicon::lib::asset {

    /**
     * @brief Represents a raw binary file loaded into memory.
     * Use for any non-text, structured or opaque file format.
     */
    class BinaryAsset : public Asset {
    public:
        explicit BinaryAsset(const std::string& path);
        ~BinaryAsset() override = default;

        /**
         * @brief Returns a const reference to the raw data buffer.
         */
        const std::vector<uint8_t>& getData() const;

        /**
         * @brief Returns the size (in bytes) of the loaded binary content.
         */
        size_t getSize() const;

        /**
         * @brief Textual representation for logging/debug/editor use.
         */
        std::string to_string() const override;

    private:
        std::vector<uint8_t> m_data;
    };

}
