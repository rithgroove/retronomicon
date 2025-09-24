#pragma once

#include "retronomicon/core/ecs/component.h"
#include "retronomicon/graphics/texture.h"

namespace retronomicon::core::ecs {

    /**
     * @brief Component defining the spatial bounds (size and offset) of an entity.
     *
     * Used for rendering alignment, collisions, and culling.
     */
    class BoundComponent : public Component {
    public:
        BoundComponent();
        BoundComponent(float width, float height, float offsetX = 0.0f, float offsetY = 0.0f);

        /// Setters
        void setSize(float width, float height);
        void setOffset(float offsetX, float offsetY);

        /// Getters
        float getWidth() const;
        float getHeight() const;
        float getOffsetX() const;
        float getOffsetY() const;

        /// Fit bounds to a texture’s dimensions
        void fitToTexture(const retronomicon::graphics::Texture& texture);

    private:
        float m_width;
        float m_height;
        float m_offsetX;
        float m_offsetY;
    };

} // namespace retronomicon::core::ecs
