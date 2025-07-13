#include "retronomicon/lib/asset/binary_asset.h"
#include <fstream>
#include <stdexcept>
#include <sstream>

namespace retronomicon::lib::asset {

BinaryAsset::BinaryAsset(const std::string& path) {
    m_path = path;

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

const std::vector<uint8_t>& BinaryAsset::getData() const {
    return m_data;
}

size_t BinaryAsset::getSize() const {
    return m_data.size();
}

std::string BinaryAsset::to_string() const {
    return "[BinaryAsset] " + m_path + " (" + std::to_string(m_data.size()) + " bytes)";
}

}
