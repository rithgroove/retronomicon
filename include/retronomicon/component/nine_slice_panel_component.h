#pragma once

#include <memory>
#include "retronomicon/component/component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/component/transform_component.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/math/rect.h"
#include "retronomicon/graphics/texture.h"
#include "retronomicon/manager/texture_manager.h"

namespace retronomicon::component {

    using retronomicon::asset::ImageAsset;
    using retronomicon::graphics::Texture;
    using retronomicon::manager::TextureManager;
    using retronomicon::math::Rect;
    using retronomicon::graphics::renderer::IRenderer;

    /**
     * @brief Renders a resizable panel using 9-slicing.
     *
     * A nine-slice panel divides an image into:
     *  - 4 corners (not stretched),
     *  - 4 edges (stretched in one axis),
     *  - 1 center (stretched in both axes).
     *
     * This component:
     *  - loads the source image,
     *  - instructs a backend TextureManager to generate a sliced texture,
     *  - renders the padded/stretched result according to the entity transform.
     *
     * Typical usage:
     *  1. Attach component with an ImageAsset,
     *  2. Call `setSlices()` to define border sizes,
     *  3. Call `setSize()` to define panel dimensions,
     *  4. Call `generateTexture()` once the TextureManager is available.
     */
    class NineSlicePanelComponent : public Component,
                                    public Renderable {
    public:
        /**
         * @brief Construct panel with the specified source image.
         *
         * @param imageAsset Raw image asset containing the panel graphic.
         */
        NineSlicePanelComponent(std::shared_ptr<ImageAsset> imageAsset);

        ~NineSlicePanelComponent() override = default;

        /**
         * @brief Initialize component references (e.g., TransformComponent).
         *
         * Called automatically by the ECS when the entity is activated.
         */
        void start() override;

        /**
         * @brief Render the nine-sliced panel.
         *
         * The renderer backend receives the final stretched/sliced texture.
         *
         * @param renderer Active renderer instance.
         */
        void render(std::shared_ptr<IRenderer> renderer) override;

        /**
         * @brief Define the pixel borders used for slicing.
         *
         * @param left   Left border width.
         * @param right  Right border width.
         * @param top    Top border height.
         * @param bottom Bottom border height.
         */
        void setSlices(int left, int right, int top, int bottom);

        /**
         * @brief Set the final output size of the panel.
         *
         * @param width  Desired width in pixels.
         * @param height Desired height in pixels.
         */
        void setSize(int width, int height);

        /**
         * @brief Replace the source image asset.
         *
         * Does not regenerate the texture automatically—call `generateTexture()`.
         *
         * @param asset New image asset.
         */
        void setAsset(std::shared_ptr<ImageAsset> asset);

        /**
         * @brief Generate the backend texture for the panel.
         *
         * This splits the image into nine regions and uploads them
         * to the backend texture system for efficient rendering.
         *
         * @param textureManager The backend's TextureManager.
         */
        void generateTexture(std::shared_ptr<TextureManager> textureManager);

    private:
        /// Raw source image for the nine-slice operation.
        std::shared_ptr<ImageAsset> m_image = nullptr;

        /// Backend-generated texture representing the sliced panel.
        std::shared_ptr<Texture>    m_texture = nullptr;

        /// Reference to owning entity's transform.
        std::shared_ptr<TransformComponent> m_transform = nullptr;

        // Slice borders
        int m_sliceLeft   = 0;
        int m_sliceRight  = 0;
        int m_sliceTop    = 0;
        int m_sliceBottom = 0;

        // Target dimensions
        int m_width  = 0;
        int m_height = 0;
    };

} // namespace retronomicon::component
