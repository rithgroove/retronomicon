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

    class TextLabelComponent : public Component, public Renderable {
    public:
        TextLabelComponent(std::shared_ptr<FontAsset> font,
                           const std::string& text = "",
                           const Color& color = Color::White());

        ~TextLabelComponent() override = default;

        void start() override;
        void update(float dt) override {}

        void render(std::shared_ptr<retronomicon::graphics::renderer::IRenderer> renderer) override;

        void setText(const std::string& text);
        void setColor(const Color& color);
        void setFont(std::shared_ptr<FontAsset> font);

        const std::string& getText() const { return m_text; }
        const Color& getColor() const { return m_color; }
        std::shared_ptr<FontAsset> getFont() const { return m_font; }

        // Backend generates texture atlas using TextureManager
        void generateTexture(std::shared_ptr<TextureManager> textureManager);

    private:
        std::shared_ptr<FontAsset> m_font = nullptr;
        std::shared_ptr<Texture>   m_texture = nullptr;

        std::shared_ptr<TransformComponent> m_transform = nullptr;
        std::shared_ptr<BoundComponent>     m_bound = nullptr;

        std::string m_text;
        Color       m_color;

        float m_lineSpacing = 0.0f;
    };

} // namespace retronomicon::component
