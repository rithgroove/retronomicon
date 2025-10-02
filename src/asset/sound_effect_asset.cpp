#include "retronomicon/asset/sound_effect_asset.h"
#include <stdexcept>

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::asset {
    /***************************** Constructor *****************************/
    
    /**
     * @brief Constructor for the sfx asset
     *
     * @param path the path to the sfx
     * @param name the name of the sfx
     */
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

    /***************************** Destructor *****************************/

    /**
     * @brief Destructor for the sfx asset
     *
     * Releases the asset from memory
     */
    SoundEffectAsset::~SoundEffectAsset() {
        if (m_chunk) {
            Mix_FreeChunk(m_chunk);
            m_chunk = nullptr;
        }
    }

    /***************************** To String *****************************/

    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string SoundEffectAsset::to_string() const {
        return "[SoundEffectAsset] " + m_path;
    }

}