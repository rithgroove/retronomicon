#pragma once

#include <string>
#include "retronomicon/lib/asset/asset.h"

namespace retronomicon::lib::asset {

    /**
     * @brief Represents a text-based asset loaded from file (e.g., .txt, .json).
     */
    class TextAsset : public Asset {
        public:
            explicit TextAsset(const std::string& path,const std::string& name);
            ~TextAsset() override = default;

            /**
             * @brief Returns the full contents of the file as a string.
             */
            const std::string& getContent() const;

           /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const override;

        private:
            std::string m_content;
    };

}
