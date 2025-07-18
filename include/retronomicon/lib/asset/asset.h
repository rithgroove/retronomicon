#pragma once

#include <string>

namespace retronomicon::lib::asset {

class Asset {
    public:
        virtual ~Asset() = default;

        // For logging, editor, debug UI
        virtual std::string to_string() const = 0;

        // Optional: path getter if all assets come from file
        std::string getPath(){
            return m_path;
        }
        
        std::string getName(){
            return m_name;
        }

    protected:

        std::string m_path;
        std::string m_name;
    };
}