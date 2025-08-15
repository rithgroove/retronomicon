#include "menu_input_item_component.h"
#include <iostream>

namespace retronomicon::lib::scene::menu {

void MenuInputItemComponent::start() {
    m_transform = getOwner()->getComponent<core::TransformComponent>();
    if (!m_transform) {
        std::cout << "[MenuInputItemComponent] Missing TransformComponent on entity.\n";
    }
}

void MenuInputItemComponent::regenerateTexture(SDL_Renderer* renderer) {
    if (!m_font) return;

    // Choose color based on selection
    SDL_Color textColor = m_is_selected
        ? SDL_Color{255, 255, 0, 255} // yellow highlight
        : SDL_Color{255, 255, 255, 255}; // white normal

    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }

    m_texture = m_font->generateTexture(
        m_label,
        0, 0, // padding
        0, 0, // auto size
        textColor,
        {0, 0, 0, 0} // no shadow
    );

    m_dirty = false;
}

void MenuInputItemComponent::render(SDL_Renderer* renderer) {
    if (!m_transform) return;

    if (m_dirty || !m_texture) {
        regenerateTexture(renderer);
    }
    if (!m_texture) return;

    int texW = 0, texH = 0;
    SDL_QueryTexture(m_texture, nullptr, nullptr, &texW, &texH);

    SDL_Rect dstRect = {
        static_cast<int>(m_transform->position.x),
        static_cast<int>(m_transform->position.y),
        texW, texH
    };

    SDL_RenderCopy(renderer, m_texture, nullptr, &dstRect);
}

} // namespace retronomicon::lib::scene::menu
