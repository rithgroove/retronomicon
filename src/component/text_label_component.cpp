#include "retronomicon/component/text_label_component.h"
#include "retronomicon/entity/entity.h"
#include <iostream>

namespace retronomicon::component {

using retronomicon::math::Rect;
using retronomicon::math::Point;
using retronomicon::graphics::renderer::IRenderer;

TextLabelComponent::TextLabelComponent(
    std::shared_ptr<FontAsset> font,
    std::shared_ptr<Color> color,
    const std::string& text)
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

void TextLabelComponent::setColor(std::shared_ptr<Color> c) {
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
    std::cout<<pos<<std::endl;
    float scaleX = m_transform->getScaleX();
    float scaleY = m_transform->getScaleY();
    float rotation = m_transform->getRotation();
    float anchorX = m_transform->getAnchorX();
    float anchorY = m_transform->getAnchorY();

    float cursorX = 0.0f;
    float cursorY = 0.0f;

    for (char c : m_text) {
        if (c == '\n') {
            cursorX = 0.0f;
            cursorY += (m_font->getPointSize() + m_lineSpacing) * scaleY;
            continue;
        }

        const auto* gm = m_font->getGlyph(c);
        if (!gm) continue;
        if (gm->width == 0 || gm->height == 0) {
            cursorX += gm->advanceX * scaleX;
            continue;
        }

        float glyphW = gm->width * scaleX;
        float glyphH = gm->height * scaleY;

        float destX = pos.x + cursorX + gm->bearingX * scaleX - glyphW * anchorX;
        float destY = pos.y + cursorY - (gm->bearingY * scaleY) + m_font->getMaxGlyphHeight() - glyphH * anchorY ;

        Rect src(
            (float)gm->atlasX,
            (float)gm->atlasY,
            (float)gm->width,
            (float)gm->height
        );
        Rect dst(
            destX,
            destY,
            glyphW,
            glyphH
        );

        renderer->renderQuad(
            m_texture,
            dst,
            src,
            rotation,
            m_color->a(),
            *m_color
        );

        cursorX += gm->advanceX * scaleX;
    }

}

} // namespace retronomicon::component
