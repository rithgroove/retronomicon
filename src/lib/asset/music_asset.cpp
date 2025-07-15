#include "retronomicon/lib/asset/music_asset.h"
#include <stdexcept>

namespace retronomicon::lib::asset {

    MusicAsset::MusicAsset(const std::string& path,
                         const std::string& name)
        : m_music(nullptr)
    {
        m_path = path;
        m_name = name; 

        m_music = Mix_LoadMUS(path.c_str());
        if (!m_music) {
            throw std::runtime_error("Failed to load music from " + path +
                                     ": " + Mix_GetError());
        }
    }

    MusicAsset::~MusicAsset() {
        if (m_music) {
            Mix_FreeMusic(m_music);
            m_music = nullptr;
        }
    }

    Mix_Music* MusicAsset::getRawMusic() const {
        return m_music;
    }

    std::string MusicAsset::to_string() const {
        return "[MusicAsset] " + m_path;
    }

    bool MusicAsset::isValid() const {
        return m_music != nullptr;
    }


}
