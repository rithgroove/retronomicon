#include "retronomicon/asset/music_asset.h"
#include <stdexcept>
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::asset {

    /***************************** Constructor *****************************/
    
    /**
     * @brief Constructor for the music asset
     *
     * @param path the path to the music
     * @param name the name of the music
     */
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

    /***************************** Destructor *****************************/

    /**
     * @brief Destructor for the music asset
     *
     * Releases the asset from memory
     */
    MusicAsset::~MusicAsset() {
        if (m_music) {
            Mix_FreeMusic(m_music);
            m_music = nullptr;
        }
    }

    /***************************** To String *****************************/

    /**
     * @brief Textual representation of this asset (for debugging / editor)
     * 
     * @return string representation
     */
    std::string MusicAsset::to_string() const {
        return "[MusicAsset] " + m_path;
    }

}
