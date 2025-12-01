#include "retronomicon/component/nine_slice_panel_component.h"
#include "retronomicon/entity/entity.h"
#include <iostream>

namespace retronomicon::component {

    NineSlicePanelComponent::NineSlicePanelComponent(std::shared_ptr<ImageAsset> imageAsset)
        : m_image(std::move(imageAsset))
    {}

    void NineSlicePanelComponent::start() {
        m_transform = getOwner()->getComponent<TransformComponent>();
        if (!m_transform) {
            std::cerr << "[NineSlicePanelComponent] Missing TransformComponent.\n";
        }
    }

    void NineSlicePanelComponent::setAsset(std::shared_ptr<ImageAsset> asset) {
        m_image = std::move(asset);
        m_texture.reset(); // must regenerate later
    }

    void NineSlicePanelComponent::generateTexture(std::shared_ptr<TextureManager> textureManager) {
        if (m_image)
            m_texture = textureManager->createTexture(m_image);
    }

    void NineSlicePanelComponent::setSlices(int left, int right, int top, int bottom) {
        m_sliceLeft   = left;
        m_sliceRight  = right;
        m_sliceTop    = top;
        m_sliceBottom = bottom;
    }

    void NineSlicePanelComponent::setSize(int width, int height) {
        m_width  = width;
        m_height = height;
    }

    void NineSlicePanelComponent::render(std::shared_ptr<IRenderer> renderer) {
        if (!isVisible()) return;
        if (!renderer) return;
        if (!m_transform || !m_texture || !m_image) return;

        int texW = m_image->getWidth();
        int texH = m_image->getHeight();

        // --- scale and position from TransformComponent ---
        Vec2 pos = m_transform->getRenderPosition();
        float scaleX = m_transform->getScaleX();
        float scaleY = m_transform->getScaleY();

        // final scaled size
        float scaledW = m_width  * scaleX;
        float scaledH = m_height * scaleY;

        float centerSrcW = texW - m_sliceLeft - m_sliceRight;
        float centerSrcH = texH - m_sliceTop - m_sliceBottom;

        float centerDstW = scaledW  - m_sliceLeft - m_sliceRight;
        float centerDstH = scaledH - m_sliceTop - m_sliceBottom;

        if (centerDstW < 0) centerDstW = 0;
        if (centerDstH < 0) centerDstH = 0;

        // --- 9 source rects ---
        Rect src[9] = {
            Rect(0, 0, m_sliceLeft, m_sliceTop),
            Rect(m_sliceLeft, 0, centerSrcW, m_sliceTop),
            Rect(m_sliceLeft + centerSrcW, 0, m_sliceRight, m_sliceTop),

            Rect(0, m_sliceTop, m_sliceLeft, centerSrcH),
            Rect(m_sliceLeft, m_sliceTop, centerSrcW, centerSrcH),
            Rect(m_sliceLeft + centerSrcW, m_sliceTop, m_sliceRight, centerSrcH),

            Rect(0, m_sliceTop + centerSrcH, m_sliceLeft, m_sliceBottom),
            Rect(m_sliceLeft, m_sliceTop + centerSrcH, centerSrcW, m_sliceBottom),
            Rect(m_sliceLeft + centerSrcW, m_sliceTop + centerSrcH, m_sliceRight, m_sliceBottom)
        };

        float x = pos.x;
        float y = pos.y;

        // --- 9 destination rects ---
        Rect dst[9] = {
            Rect(x, y, m_sliceLeft, m_sliceTop),
            Rect(x + m_sliceLeft, y, centerDstW, m_sliceTop),
            Rect(x + m_sliceLeft + centerDstW, y, m_sliceRight, m_sliceTop),

            Rect(x, y + m_sliceTop, m_sliceLeft, centerDstH),
            Rect(x + m_sliceLeft, y + m_sliceTop, centerDstW, centerDstH),
            Rect(x + m_sliceLeft + centerDstW, y + m_sliceTop, m_sliceRight, centerDstH),

            Rect(x, y + m_sliceTop + centerDstH, m_sliceLeft, m_sliceBottom),
            Rect(x + m_sliceLeft, y + m_sliceTop + centerDstH, centerDstW, m_sliceBottom),
            Rect(x + m_sliceLeft + centerDstW, y + m_sliceTop + centerDstH, m_sliceRight, m_sliceBottom)
        };

        // Render using existing backend quad rendering
        for (int i = 0; i < 9; ++i) {
            renderer->renderQuad(m_texture, dst[i], src[i], m_transform->getRotation(), 1.0f);
        }
    }

} // namespace retronomicon::component
