#include "retronomicon/lib/asset/binary_asset.h"

#include <fstream>
#include <stdexcept>
#include <sstream>

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {

    /**
     * @brief Constructor for the binary asset
     *
     * @param path path the file
     * @param name the given name for this font
     */
    BinaryAsset::BinaryAsset(const std::string& path,const std::string& name) {
        m_path = path;
        m_name = name;

        std::ifstream file(path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to load binary file: " + path);
        }

        file.seekg(0, std::ios::end);
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        if (size > 0) {
            m_data.resize(static_cast<size_t>(size));
            if (!file.read(reinterpret_cast<char*>(m_data.data()), size)) {
                throw std::runtime_error("Failed to read binary data from: " + path);
            }
        }
    }

    /***************************** Getter *****************************/

    /**
     * @brief Textual representation for logging/debug/editor use.
     */
    std::string BinaryAsset::to_string() const {
        return "[BinaryAsset] " + m_path + " (" + std::to_string(m_data.size()) + " bytes)";
    }

}
