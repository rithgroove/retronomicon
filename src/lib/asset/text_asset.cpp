#include "retronomicon/lib/asset/text_asset.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {
   /***************************** Constructor *****************************/
    
    /**
     * @brief Constructor for the text file asset
     *
     * @param path the path to the text file
     * @param name the name of the text file
     */
    TextAsset::TextAsset(const std::string& path,const std::string& name){
        m_path = path;
        m_name = name;
        std::ifstream file(path);
        if (!file) {
            throw std::runtime_error("Failed to load text file: " + path);
        }

        std::ostringstream ss;
        ss << file.rdbuf();
        m_content = ss.str();
    }

    /***************************** To String *****************************/

    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string TextAsset::to_string() const {
        return "[TextAsset] " + m_path + " (" + std::to_string(m_content.size()) + " bytes)";
    }
}
