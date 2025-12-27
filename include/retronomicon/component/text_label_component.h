#pragma once

#include <memory>
#include <string>
#include <vector>

#include "retronomicon/component/component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/component/transform_component.h"
#include "retronomicon/component/bound_component.h"

#include "retronomicon/asset/font_asset.h"
#include "retronomicon/graphics/texture.h"
#include "retronomicon/graphics/color.h"
#include "retronomicon/math/rect.h"
#include "retronomicon/manager/texture_manager.h"

namespace retronomicon::component {

    using retronomicon::asset::FontAsset;
    using retronomicon::graphics::Texture;
    using retronomicon::graphics::Color;
    using retronomicon::math::Rect;
    using retronomicon::manager::TextureManager;

    /**
     * @brief Component for rendering static or dynamic text labels.
     *
     * TextLabelComponent is a renderable UI / world-space text component that:
     *  - holds a string value,
     *  - references a FontAsset for glyph data,
     *  - generates a backend-specific texture via TextureManager,
     *  - renders the resulting texture using the active renderer.
     *
     * This component does not rasterize glyphs itself. Instead:
     *  - the backend font implementation prepares glyph atlases,
     *  - TextureManager creates and manages the GPU texture,
     *  - the renderer draws the generated texture.
     *
     * A TransformComponent is used for positioning,
     * and a BoundComponent is used for size / layout information.
     */
    class TextLabelComponent : public Component, public Renderable {
    public:
        /**
         * @brief Construct a text label component.
         *
         * @param font  Shared FontAsset used to render the text.
         * @param color Text color (RGBA, normalized).
         * @param text  Initial text content (optional).
         */
        TextLabelComponent(std::shared_ptr<FontAsset> font,
                           std::shared_ptr<Color> color,
                           const std::string& text = "");

        /**
         * @brief Default destructor.
         */
        ~TextLabelComponent() override = default;

        /**
         * @brief Called when the component is first activated.
         *
         * Typically used to:
         *  - cache TransformComponent and BoundComponent references,
         *  - prepare initial rendering state.
         */
        void start() override;

        /**
         * @brief Update callback.
         *
         * TextLabelComponent does not require per-frame updates by default.
         *
         * @param dt Delta time in seconds.
         */
        void update(float dt) override {}

        /**
         * @brief Render the text label.
         *
         * Draws the generated text texture using the provided renderer.
         *
         * @param renderer Active rendering backend interface.
         */
        void render(std::shared_ptr<retronomicon::graphics::renderer::IRenderer> renderer) override;

        /**
         * @brief Set the displayed text.
         *
         * Changing the text typically requires regenerating the texture.
         *
         * @param text New text string.
         */
        void setText(const std::string& text);

        /**
         * @brief Set the text color.
         *
         * @param color New color (shared).
         */
        void setColor(std::shared_ptr<Color> color);

        /**
         * @brief Set the font asset.
         *
         * Changing the font requires regenerating the texture.
         *
         * @param font New font asset.
         */
        void setFont(std::shared_ptr<FontAsset> font);

        /**
         * @brief Get the current text string.
         */
        const std::string& getText() const { return m_text; }

        /**
         * @brief Get the current text color.
         */
        const std::shared_ptr<Color> getColor() const { return m_color; }

        /**
         * @brief Get the current font asset.
         */
        std::shared_ptr<FontAsset> getFont() const { return m_font; }

        /**
         * @brief Generate or regenerate the text texture.
         *
         * Uses the TextureManager to create a backend-specific texture
         * based on the current text, font, and color.
         *
         * This should be called when:
         *  - text changes,
         *  - font changes,
         *  - font size or glyph atlas changes.
         *
         * @param textureManager Active texture manager.
         */
        void generateTexture(std::shared_ptr<TextureManager> textureManager);

    private:
        /** Font used for glyph lookup and layout */
        std::shared_ptr<FontAsset> m_font = nullptr;

        /** Generated texture containing the rendered text */
        std::shared_ptr<Texture>   m_texture = nullptr;

        /** Cached transform for positioning */
        std::shared_ptr<TransformComponent> m_transform = nullptr;

        /** Cached bounds for size and layout */
        std::shared_ptr<BoundComponent>     m_bound = nullptr;

        /** Text content */
        std::string m_text;

        /** Text color */
        std::shared_ptr<Color> m_color;

        /** Extra spacing between lines (backend-dependent) */
        float m_lineSpacing = 0.0f;
    };

} // namespace retronomicon::component
