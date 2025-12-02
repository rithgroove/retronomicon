#pragma once

#include <string>
#include <memory>
#include <SDL.h>

#include "retronomicon/component/component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/asset/font_asset.h"
#include "retronomicon/math/rect.h"
namespace retronomicon::component {

    using retronomicon::lib::math::Rect;
    using retronomicon::asset::FontAsset;
    /**
     * @brief A simple text label component that can be attached to an entity.
     */
    class TextLabelComponent : public Component, public Renderable {
    public:
        TextLabelComponent(const std::string& text,
                           std::shared_ptr<asset::FontAsset> font,
                           SDL_Color color = {255, 255, 255, 255},
                           int width = 0,
                           int height = 0,
                           int paddingX = 0,
                           int paddingY = 0);

        ~TextLabelComponent() override;

        void setText(const std::string& newText);
        void setColor(SDL_Color newColor);
        void setFont(std::shared_ptr<FontAsset> newFont);
        void setPadding(int horizontal, int vertical);
        Rect getSize() override;

        const std::string& getText() const;
        SDL_Color getColor() const;
        std::shared_ptr<FontAsset> getFont() const;

        void render(SDL_Renderer* renderer) override;

    private:
        std::string text;
        SDL_Color color;
        int paddingX;
        int paddingY;

        std::shared_ptr<FontAsset> font;

        SDL_Texture* texture = nullptr;
        int width = 0;
        int height = 0;

        void regenerateTexture();
    };

} // namespace retronomicon::lib::ui
