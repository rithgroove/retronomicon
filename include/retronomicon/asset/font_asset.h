#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "retronomicon/asset/asset.h"

namespace retronomicon::asset {

    /**
     * @brief Represents a backend-agnostic font resource.
     *        Stores font metadata such as size and glyph metrics.
     *        Backend (OpenGL/SDL/etc.) will implement the actual loading/rasterization.
     */
    class FontAsset : public Asset {
    public:

        struct GlyphMetrics {
            int advanceX = 0;
            int advanceY = 0;
            int bearingX = 0;
            int bearingY = 0;
            int width    = 0;
            int height   = 0;
        };

        /**
         * @brief Constructor using path
         */
        explicit FontAsset(const std::string& path, int pointSize)
            : Asset(path), m_pointSize(pointSize) {}

        /**
         * @brief Constructor using custom name
         */
        FontAsset(const std::string& path, const std::string& name, int pointSize)
            : Asset(path, name), m_pointSize(pointSize) {}

        virtual ~FontAsset() = default;

        /***************************** Load / Unload *****************************/
        virtual bool load() = 0;
        virtual void unload() = 0;
        virtual bool isLoaded() const noexcept = 0;

        /***************************** Getters *****************************/
        int getPointSize() const noexcept { return m_pointSize; }

        const GlyphMetrics* getGlyph(char c) const noexcept {
            auto it = m_glyphs.find(c);
            return (it != m_glyphs.end()) ? &it->second : nullptr;
        }

        /***************************** To String *****************************/
        std::string to_string() const override {
            return "FontAsset(name=" + m_name +
                   ", path=" + m_path +
                   ", size=" + std::to_string(m_pointSize) + ")";
        }

    protected:
        int m_pointSize;
        std::unordered_map<char, GlyphMetrics> m_glyphs;
    };

} // namespace retronomicon::asset
