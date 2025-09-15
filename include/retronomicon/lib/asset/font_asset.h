#pragma once

#include <string>
#include <vector>
#include <memory>
#include "retronomicon/lib/asset/asset.h"
#include "retronomicon/lib/math/color.h"
#include "retronomicon/lib/graphics/texture.h"

namespace retronomicon::lib::asset {

    class FontAsset : public Asset {
    public:
        FontAsset(const std::string& filePath,
                  const std::string& name,
                  int fontSize);

        ~FontAsset() override;

        int getLineHeight() const;
        int measureTextWidth(const std::string& text) const;
        bool isInitialized() const { return m_initialized; }
        int getFontSize() const { return m_fontSize; }

        /**
         * @brief Generate a rendered texture from text.
         * 
         * This returns a backend-neutral Texture. Implementation decides
         * whether it becomes an OpenGL texture, Vulkan image, etc.
         */
        std::unique_ptr<retronomicon::lib::graphics::Texture> generateTexture(
            const std::string& text,
            int horizontalPadding,
            int verticalPadding,
            int width,
            int height,
            retronomicon::lib::math::Color fgC,
            retronomicon::lib::math::Color bgC
        );

        bool measureText(const std::string& text, int& w, int& h) const;
        std::vector<std::string> wrapText(const std::string& text, int maxWidth) const;

        std::string to_string() const override;

    private:
        int m_fontSize = 0;
        bool m_initialized = false;

        struct Impl;
        std::unique_ptr<Impl> m_impl;
    };

}
