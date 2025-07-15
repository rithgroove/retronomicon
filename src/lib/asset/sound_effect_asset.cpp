#include "retronomicon/lib/asset/sound_effect_asset.h"
#include <stdexcept>

namespace retronomicon::lib::asset {

SoundEffectAsset::SoundEffectAsset(const std::string& path,const std::string& name)
    : m_chunk(nullptr)
 {
    m_path = path;
    m_name = name;

    m_chunk = Mix_LoadWAV(path.c_str());
    if (!m_chunk) {
        throw std::runtime_error("Failed to load sound from " + path +
                                 ": " + Mix_GetError());
    }
}

SoundEffectAsset::~SoundEffectAsset() {
    if (m_chunk) {
        Mix_FreeChunk(m_chunk);
        m_chunk = nullptr;
    }
}

Mix_Chunk* SoundEffectAsset::getRawSound() const {
    return m_chunk;
}

std::string SoundEffectAsset::to_string() const {
    return "[SoundEffectAsset] " + m_path;
}

}