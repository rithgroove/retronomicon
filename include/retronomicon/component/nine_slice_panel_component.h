#pragma once

#include <memory>
#include "retronomicon/component/component.h"
#include "retronomicon/component/renderable.h"
#include "retronomicon/graphics/renderer/i_renderer.h"
#include "retronomicon/component/transform_component.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/math/rect.h"

namespace retronomicon::component {

    using retronomicon::asset::ImageAsset;
    using retronomicon::math::Rect;
    using retronomicon::graphics::renderer::IRenderer;

    /**
     * @brief Backend-agnostic 9-slice UI panel component.
     *
     * Stores margins, size, and an image asset. Rendering is performed by
     * backend-specific renderers (OpenGL, SDL, etc.) via IRenderer.
     */
    class NineSlicePanelComponent : public Component,
                                    public Renderable {
    public:
        NineSlicePanelComponent();
        ~NineSlicePanelComponent() override = default;

        void setImageAsset(std::shared_ptr<ImageAsset> asset);
        void setSlices(int left, int right, int top, int bottom);
        void setSize(int width, int height);

        std::shared_ptr<ImageAsset> getAsset() const { return m_imageAsset; }

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        int getLeft() const { return m_sliceLeft; }
        int getRight() const { return m_sliceRight; }
        int getTop() const { return m_sliceTop; }
        int getBottom() const { return m_sliceBottom; }

        void start() override;
        // Rect getSize() override;

        /**
         * @brief Calls into backend renderer. Core component never depends on SDL/OpenGL.
         */
        void render(IRenderer& renderer) override;

    private:
        std::shared_ptr<ImageAsset> m_imageAsset;

        TransformComponent* m_transform = nullptr;

        int m_sliceLeft   = 0;
        int m_sliceRight  = 0;
        int m_sliceTop    = 0;
        int m_sliceBottom = 0;

        int m_width  = 0;
        int m_height = 0;
    };

} // namespace retronomicon::component
