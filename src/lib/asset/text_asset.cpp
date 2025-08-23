#include "retronomicon/lib/asset/text_asset.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace retronomicon::lib::asset {

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

    const std::string& TextAsset::getContent() const {
        return m_content;
    }
   /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string TextAsset::to_string() const {
        return "[TextAsset] " + m_path + " (" + std::to_string(m_content.size()) + " bytes)";
    }

}
