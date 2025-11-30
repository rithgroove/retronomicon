#pragma once

#include "component.h"

namespace retronomicon::component {

    enum class ScaleMode {
        Contain, // Fit entirely inside the bounds (no cropping)
        Cover    // Fill the bounds completely (may crop)
    };

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
        void setScaleMode(ScaleMode mode);

        /// Getters
        float getWidth() const;
        float getHeight() const;
        float getOffsetX() const;
        float getOffsetY() const;
        ScaleMode getScaleMode() const;

    private:
        float m_width;
        float m_height;
        float m_offsetX;
        float m_offsetY;

        ScaleMode m_scaleMode = ScaleMode::Contain;
    };

} // namespace retronomicon::component
