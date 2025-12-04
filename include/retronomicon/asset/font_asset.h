#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "retronomicon/asset/asset.h"

namespace retronomicon::asset {

    /**
     * @brief Backend-agnostic font definition.
     *
     * Backends (SDL/OpenGL/etc.) load font files, rasterize glyphs, build
     * a texture atlas, and fill glyph metrics + atlas positions.
     *
     * FontAsset stores:
     *  - point size
     *  - per-glyph metrics
     *  - per-glyph atlas coordinates (in pixels)
     */
    class FontAsset : public Asset {
    public:

        struct GlyphMetrics {
            // Font metrics
            int advanceX = 0;
            int advanceY = 0;
            int bearingX = 0;
            int bearingY = 0;
            int width    = 0;
            int height   = 0;

            // Location of glyph inside backend-generated atlas
            int atlasX = 0;
            int atlasY = 0;

            // Optional normalized UV positions (commonly used by GL backends)
            float u0 = 0.0f;  ///< left
            float v0 = 0.0f;  ///< top
            float u1 = 0.0f;  ///< right
            float v1 = 0.0f;  ///< bottom
        };

        /**
         * @brief Construct using file path.
         */
        explicit FontAsset(const std::string& path, int pointSize)
            : Asset(path), m_pointSize(pointSize) {}

        /**
         * @brief Construct using file path and custom asset name.
         */
        FontAsset(const std::string& path, const std::string& name, int pointSize)
            : Asset(path, name), m_pointSize(pointSize) {}

        virtual ~FontAsset() = default;

        // --------------------------------------------------------------------
        // Backend API — implemented by SDL/OpenGL/etc
        // --------------------------------------------------------------------
        virtual bool load() = 0;
        virtual void unload() = 0;
        virtual bool isLoaded() const noexcept = 0;

        // --------------------------------------------------------------------
        // Getters
        // --------------------------------------------------------------------
        int getPointSize() const noexcept { return m_pointSize; }

        const GlyphMetrics* getGlyph(char c) const noexcept {
            auto it = m_glyphs.find(c);
            return (it != m_glyphs.end()) ? &it->second : nullptr;
        }

        std::unordered_map<char, GlyphMetrics>& glyphTable() noexcept {
            return m_glyphs;
        }

        const std::unordered_map<char, GlyphMetrics>& glyphTable() const noexcept {
            return m_glyphs;
        }

        // --------------------------------------------------------------------
        // Debug helper
        // --------------------------------------------------------------------
        std::string to_string() const override {
            return "FontAsset(name=" + m_name +
                   ", path=" + m_path +
                   ", size=" + std::to_string(m_pointSize) +
                   ", glyphs=" + std::to_string(m_glyphs.size()) + ")";
        }

    protected:
        int m_pointSize = 0;

        // Filled by backend after rasterization / atlas construction
        std::unordered_map<char, GlyphMetrics> m_glyphs;
    };

} // namespace retronomicon::asset
