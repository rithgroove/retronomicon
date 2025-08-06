#include "retronomicon/lib/ui/text_label_component.h"

namespace retronomicon::lib::ui {

TextLabelComponent::TextLabelComponent(const std::string& text,
                                       std::shared_ptr<asset::FontAsset> font,
                                       SDL_Color color,
                                       int paddingX,
                                       int paddingY)
    : text(text),
      font(std::move(font)),
      color(color),
      paddingX(paddingX),
      paddingY(paddingY) {
    regenerateTexture();
}

TextLabelComponent::~TextLabelComponent() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void TextLabelComponent::setText(const std::string& newText) {
    if (text != newText) {
        text = newText;
        regenerateTexture();
    }
}

void TextLabelComponent::setColor(SDL_Color newColor) {
    color = newColor;
    regenerateTexture();
}

void TextLabelComponent::setFont(std::shared_ptr<asset::FontAsset> newFont) {
    font = std::move(newFont);
    regenerateTexture();
}

void TextLabelComponent::setPadding(int horizontal, int vertical) {
    paddingX = horizontal;
    paddingY = vertical;
    regenerateTexture();
}

const std::string& TextLabelComponent::getText() const {
    return text;
}

SDL_Color TextLabelComponent::getColor() const {
    return color;
}

std::shared_ptr<asset::FontAsset> TextLabelComponent::getFont() const {
    return font;
}

void TextLabelComponent::regenerateTexture() {
    if (!font || !font->isInitialized()) return;

    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    int w = 0;
    int h = 0;

    texture = font->generateTexture(text, paddingX, paddingY, w, h, color, {0, 0, 0, 0});

    if (texture) {
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    } else {
        width = 0;
        height = 0;
    }
}

void TextLabelComponent::render(SDL_Renderer* renderer) {
    if (!texture || !getOwner()) return;

    // Example: assumes your Entity has a transform or position component
    int x = 0;
    int y = 0;

    // Get position if the Entity has it
    auto* entity = getOwner();
    // If you have a TransformComponent, grab position from there.
    // x = entity->getComponent<TransformComponent>()->x; etc.

    SDL_Rect dst = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

} // namespace retronomicon::lib::ui
