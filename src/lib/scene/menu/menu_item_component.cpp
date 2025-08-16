#include "retronomicon/lib/scene/menu/menu_item_component.h"
#include "retronomicon/lib/core/entity.h"
#include <iostream>

namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::core::Entity;

    void MenuItemComponent::start() {
        m_transform = getOwner()->getComponent<core::TransformComponent>();
        if (!m_transform) {
            std::cout << "[MenuInputItemComponent] Missing TransformComponent on entity.\n";
        }
    }


    Rect MenuItemComponent::getSize(){
        return Rect();
    }

    void MenuItemComponent::regenerateTexture(SDL_Renderer* renderer) {
        if (!m_font) return;

        // Choose color based on selection
        SDL_Color textColor = m_is_selected
            ? SDL_Color{255, 255, 255, 255} // yellow highlight
            : SDL_Color{100, 100, 100, 255}; // white normal

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

    void MenuItemComponent::render(SDL_Renderer* renderer) {
        if (!m_transform) return;

        if (m_dirty || !m_texture) {
            regenerateTexture(renderer);
        }
        if (!m_texture) return;

        int texW = 0, texH = 0;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &texW, &texH);

        Vec2 renderPosition = m_transform->getRenderPosition();
        SDL_Rect dstRect = {
            static_cast<int>(renderPosition.x),
            static_cast<int>(renderPosition.y),
            texW, texH
        };
        std::cout << "Render Position ("<<renderPosition.x<<","<<renderPosition.y<<")"<<std::endl;

        SDL_RenderCopy(renderer, m_texture, nullptr, &dstRect);
    }

} // namespace retronomicon::lib::scene::menu
