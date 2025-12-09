#pragma once

#include "component.h"

namespace retronomicon::component {

    /**
     * @brief Defines how a visual or logical element should scale within its bounds.
     *
     * - **Contain** — The element fits entirely inside the bounds without cropping.
     * - **Cover**   — The element fills the bounds completely, possibly cropping excess.
     */
    enum class ScaleMode {
        Contain, ///< Fit inside bounds, preserving aspect ratio and avoiding cropping.
        Cover    ///< Fill bounds entirely, allowing cropping when aspect ratios differ.
    };

    /**
     * @brief Describes the size and local offset of an entity.
     *
     * This component is used by:
     *  - rendering (alignment, layout, nine-slice paneling),
     *  - physics/collision systems (AABB construction),
     *  - culling/visibility checks,
     *  - UI elements and sprites requiring positional metadata.
     *
     * The width/height define the entity's bounding box in local space.
     * The offset values shift the box relative to the entity’s origin.
     */
    class BoundComponent : public Component {
    public:
        /**
         * @brief Create an empty bound with zero size.
         *
         * Useful when another system (e.g. sprite loader) will populate bounds later.
         */
        BoundComponent();

        /**
         * @brief Create a bound with specified size and optional offset.
         *
         * @param width   Width of the bounding box.
         * @param height  Height of the bounding box.
         * @param offsetX Horizontal offset from entity origin.
         * @param offsetY Vertical offset from entity origin.
         */
        BoundComponent(float width, float height,
                       float offsetX = 0.0f, float offsetY = 0.0f);

        // --------------------------------------------------------------------
        // Setters
        // --------------------------------------------------------------------

        /**
         * @brief Change the bounding box dimensions.
         *
         * @param width  New width.
         * @param height New height.
         */
        void setSize(float width, float height);

        /**
         * @brief Set the local offset from the entity origin.
         *
         * @param offsetX Horizontal offset.
         * @param offsetY Vertical offset.
         */
        void setOffset(float offsetX, float offsetY);

        /**
         * @brief Set how the entity should scale when fitted into these bounds.
         *
         * @param mode ScaleMode::Contain or ScaleMode::Cover.
         */
        void setScaleMode(ScaleMode mode);

        // --------------------------------------------------------------------
        // Getters
        // --------------------------------------------------------------------

        /**
         * @brief Get the bounding box width.
         */
        float getWidth() const;

        /**
         * @brief Get the bounding box height.
         */
        float getHeight() const;

        /**
         * @brief Get the horizontal offset from entity origin.
         */
        float getOffsetX() const;

        /**
         * @brief Get the vertical offset from entity origin.
         */
        float getOffsetY() const;

        /**
         * @brief Get the current scale mode used for layout/fitting.
         */
        ScaleMode getScaleMode() const;

    private:
        float m_width;   ///< Width of the bounding box.
        float m_height;  ///< Height of the bounding box.
        float m_offsetX; ///< Horizontal offset from origin.
        float m_offsetY; ///< Vertical offset from origin.

        ScaleMode m_scaleMode = ScaleMode::Contain; ///< How content adjusts to the bounds.
    };

} // namespace retronomicon::component
