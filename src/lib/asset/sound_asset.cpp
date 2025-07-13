#include "retronomicon/lib/asset/sound_asset.h"
#include <stdexcept>

namespace retronomicon::lib::asset {

SoundAsset::SoundAsset(const std::string& path)
    : m_chunk(nullptr)
{
    m_path = path;

    m_chunk = Mix_LoadWAV(path.c_str());
    if (!m_chunk) {
        throw std::runtime_error("Failed to load sound from " + path +
                                 ": " + Mix_GetError());
    }
}

SoundAsset::~SoundAsset() {
    if (m_chunk) {
        Mix_FreeChunk(m_chunk);
        m_chunk = nullptr;
    }
}

Mix_Chunk* SoundAsset::getRawSound() const {
    return m_chunk;
}

std::string SoundAsset::to_string() const {
    return "[SoundAsset] " + m_path;
}

}
