#include "retronomicon/component/text_label_component.h"
#include "retronomicon/entity/entity.h"
#include <iostream>

namespace retronomicon::component {

using retronomicon::math::Rect;
using retronomicon::math::Point;
using retronomicon::graphics::renderer::IRenderer;

TextLabelComponent::TextLabelComponent(
    std::shared_ptr<FontAsset> font,
    const std::string& text,
    const Color& color)
    : m_font(std::move(font))
    , m_text(text)
    , m_color(color)
{
}

void TextLabelComponent::start() {
    m_transform = getOwner()->getComponent<TransformComponent>();
    if (!m_transform) {
        std::cerr << "[TextLabelComponent] Missing TransformComponent.\n";
    }
    m_bound = getOwner()->getComponent<BoundComponent>();
}

void TextLabelComponent::setText(const std::string& t) {
    m_text = t;
}

void TextLabelComponent::setColor(const Color& c) {
    m_color = c;
}

void TextLabelComponent::setFont(std::shared_ptr<FontAsset> f) {
    m_font = std::move(f);
}

void TextLabelComponent::generateTexture(std::shared_ptr<TextureManager> texMgr) {
    if (!m_font) {
        std::cerr << "[TextLabelComponent] Cannot generate texture: no font\n";
        return;
    }
    m_texture = texMgr->createTexture(m_font);
}

void TextLabelComponent::render(std::shared_ptr<IRenderer> renderer) {
    if (!m_transform || !m_font || !m_texture) return;
    if (m_text.empty()) return;

    Vec2 pos = m_transform->getRenderPosition();
    float scaleX = m_transform->getScaleX();
    float scaleY = m_transform->getScaleY();
    float rotation = m_transform->getRotation();
    float anchorX = m_transform->getAnchorX();
    float anchorY = m_transform->getAnchorY();

    float cursorX = 0.0f;
    float cursorY = 0.0f;

    int atlasW = m_texture->getWidth();
    int atlasH = m_texture->getHeight();

    for (char c : m_text) {
        if (c == '\n') {
            cursorX = 0.0f;
            cursorY += (m_font->getPointSize() + m_lineSpacing) * scaleY;
            continue;
        }

        const auto* gm = m_font->getGlyph(c);
        if (!gm) {
            cursorX += m_font->getPointSize() * 0.5f;
            continue;
        }

        float glyphW = gm->width * scaleX;
        float glyphH = gm->height * scaleY;

        float destX = pos.x + cursorX - anchorX;
        float destY = pos.y + cursorY - anchorY;

        // Source rectangle in atlas
        Rect src(
            static_cast<float>(gm->atlasX),
            static_cast<float>(gm->atlasY),
            static_cast<float>(gm->width),
            static_cast<float>(gm->height)
        );

        // Destination rectangle in world space
        Rect dst(
            Point(destX, destY),
            Point(0.0f, 0.0f),
            glyphW,
            glyphH
        );

        renderer->renderQuad(
            m_texture,
            dst,
            src,
            rotation,
            m_color.a(),
            m_color
        );

        cursorX += gm->advanceX * scaleX;
    }
}

} // namespace retronomicon::component
