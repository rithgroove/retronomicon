#pragma once

#include <string>
#include <SDL.h>
#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/core/renderable.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/asset/font_asset.h"

namespace retronomicon::lib::scene::menu {

class MenuItemComponent : public core::Component, public core::Renderable {
    public:
        MenuItemComponent(const std::string& label, asset::FontAsset* font)
            : m_label(label), m_font(font) {}

        void start() override;
        void render(SDL_Renderer* renderer) override;

        // --- Menu interaction state ---
        bool isSelected() const { return m_is_selected; }
        void setSelected(bool selected) { 
            if (selected != m_is_selected){
                m_is_selected = selected; 
                m_dirty = true;
            }
        }

        // --- Label handling ---
        const std::string& getLabel() const { return m_label; }
        void setLabel(const std::string& label) { m_label = label; m_dirty = true; }

    private:
        std::string m_label;
        asset::FontAsset* m_font = nullptr;
        core::TransformComponent* m_transform = nullptr; // cached transform

        bool m_is_selected = false; // selection state
        bool m_dirty = true; // needs re-generate texture

        SDL_Texture* m_texture = nullptr; // cached texture for rendering

        void regenerateTexture(SDL_Renderer* renderer);
    };

} // namespace retronomicon::lib::scene::menu
