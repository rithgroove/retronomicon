#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "retronomicon/asset/asset.h"

namespace retronomicon::asset {

    /**
     * @brief Backend-agnostic representation of a font.
     *
     * A FontAsset does not directly rasterize glyphs. Instead, each rendering
     * backend (SDL, OpenGL, etc.) is responsible for:
     *  - loading the actual font file,
     *  - rasterizing each glyph,
     *  - generating a texture atlas,
     *  - filling glyph metrics and atlas coordinates.
     *
     * The FontAsset stores:
     *  - the requested point size,
     *  - metrics for each glyph,
     *  - atlas positions (pixel or normalized UV, depending on backend).
     */
    class FontAsset : public Asset {
    public:

        /**
         * @brief Metrics and atlas coordinates for a single glyph.
         *
         * These values are populated by the backend after rasterization.
         * They include typographic metrics such as advance, bearings, and
         * glyph dimensions, as well as the glyph's position inside the
         * backend-generated atlas texture.
         */
        struct GlyphMetrics {
            // --- Font metrics (used by the layout system) ---
            int advanceX = 0;  ///< Horizontal advance after rendering the glyph.
            int advanceY = 0;  ///< Vertical advance (rarely used for Latin fonts).
            int bearingX = 0;  ///< Offset from baseline to left of glyph bitmap.
            int bearingY = 0;  ///< Offset from baseline to top of glyph bitmap.
            int width    = 0;  ///< Width of the glyph bitmap in pixels.
            int height   = 0;  ///< Height of the glyph bitmap in pixels.

            // --- Atlas coordinates (in pixels) ---
            int atlasX = 0;    ///< X position inside the texture atlas.
            int atlasY = 0;    ///< Y position inside the texture atlas.

            // --- Optional normalized UV coordinates (0..1) ---
            float u0 = 0.0f;   ///< Normalized left coordinate.
            float v0 = 0.0f;   ///< Normalized top coordinate.
            float u1 = 0.0f;   ///< Normalized right coordinate.
            float v1 = 0.0f;   ///< Normalized bottom coordinate.
        };

        /**
         * @brief Create a FontAsset using only a file path.
         *
         * @param path      Path to the font file.
         * @param pointSize Target point size for rasterization.
         */
        explicit FontAsset(const std::string& path, int pointSize)
            : Asset(path), m_pointSize(pointSize) {}

        /**
         * @brief Create a FontAsset with a custom asset name.
         *
         * @param path      Path to the font file.
         * @param name      Unique asset name.
         * @param pointSize Target point size for rasterization.
         */
        FontAsset(const std::string& path, const std::string& name, int pointSize)
            : Asset(path, name), m_pointSize(pointSize) {}

        virtual ~FontAsset() = default;

        // --------------------------------------------------------------------
        // Backend API — to be implemented by SDL/OpenGL/etc.
        // --------------------------------------------------------------------

        /**
         * @brief Load the font file and generate glyph table + atlas.
         *
         * @return `true` on success, `false` on failure.
         */
        virtual bool load() = 0;

        /**
         * @brief Release backend resources (textures, glyph data).
         */
        virtual void unload() = 0;

        /**
         * @brief Check whether the backend has successfully loaded resources.
         *
         * @return `true` if the asset is ready for use.
         */
        virtual bool isLoaded() const noexcept = 0;

        // --------------------------------------------------------------------
        // Getters
        // --------------------------------------------------------------------

        /**
         * @brief Get the font point size requested at creation.
         */
        int getPointSize() const noexcept { return m_pointSize; }

        /**
         * @brief Retrieve metrics for a specific character.
         *
         * @param c The character to query.
         * @return Pointer to glyph metrics, or `nullptr` if glyph is missing.
         */
        const GlyphMetrics* getGlyph(char c) const noexcept {
            auto it = m_glyphs.find(c);
            return (it != m_glyphs.end()) ? &it->second : nullptr;
        }

        /**
         * @brief Access the internal glyph table.
         *
         * Modifying this is typically backend-only.
         *
         * @return Reference to mutable glyph map.
         */
        std::unordered_map<char, GlyphMetrics>& glyphTable() noexcept {
            return m_glyphs;
        }

        /**
         * @brief Get read-only access to the glyph table.
         *
         * @return Const reference to glyph map.
         */
        const std::unordered_map<char, GlyphMetrics>& glyphTable() const noexcept {
            return m_glyphs;
        }
        int getMaxGlyphHeight() const noexcept {
            if (m_metricsDirty) {
                recomputeMetricsCache();
            }
            return m_cachedMaxGlyphHeight;
        }

        int getMaxAscent() const noexcept {
            if (m_metricsDirty) {
                recomputeMetricsCache();
            }
            return m_cachedMaxAscent;
        }

        int getMaxVerticalExtent() const noexcept {
            if (m_metricsDirty) {
                recomputeMetricsCache();
            }
            return m_cachedMaxVerticalExtent;
        }
        // --------------------------------------------------------------------
        // Debug helper
        // --------------------------------------------------------------------

        /**
         * @brief Debug string summarizing the asset.
         */
        std::string to_string() const override {
            return "FontAsset(name=" + m_name +
                   ", path=" + m_path +
                   ", size=" + std::to_string(m_pointSize) +
                   ", glyphs=" + std::to_string(m_glyphs.size()) + ")";
        }

        void recomputeMetricsCache() const noexcept {
            int maxHeight = 0;
            
            int maxAscent = 0;
            int top = 0;
            int bottom = 0;

            for (const auto& [_, glyph] : m_glyphs) {
                maxHeight = std::max(maxHeight, glyph.height);
                maxAscent = std::max(maxAscent, glyph.bearingY);

                top = std::max(top, glyph.bearingY);
                bottom = std::min(bottom, glyph.bearingY - glyph.height);
            }

            m_cachedMaxGlyphHeight = maxHeight;
            m_cachedMaxAscent = maxAscent;
            m_cachedMaxVerticalExtent = top - bottom;

            m_metricsDirty = false;
        }
    protected:
        int m_pointSize = 0;  ///< Requested point size used during rasterization.
        mutable bool m_metricsDirty = true;

        mutable int m_cachedMaxGlyphHeight   = 0;
        mutable int m_cachedMaxAscent        = 0;
        mutable int m_cachedMaxVerticalExtent = 0;
        void markMetricsDirty() const noexcept {
            m_metricsDirty = true;
        }
        /**
         * @brief Populated by the backend after font loading/rasterization.
         *
         * Keys are single-byte characters. Complex Unicode handling would
         * require a different structure or UTF-32 keys.
         */
        std::unordered_map<char, GlyphMetrics> m_glyphs;
    };

} // namespace retronomicon::asset
