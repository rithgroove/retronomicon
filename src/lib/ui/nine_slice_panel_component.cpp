#include "retronomicon/lib/ui/nine_slice_panel_component.h"
#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/core/entity.h"

namespace retronomicon::lib::ui {

NineSlicePanelComponent::NineSlicePanelComponent() = default;

void NineSlicePanelComponent::setImageAsset(std::shared_ptr<retronomicon::lib::asset::ImageAsset> asset) {
    m_imageAsset = std::move(asset);
}

void NineSlicePanelComponent::setSlices(int left, int right, int top, int bottom) {
    m_sliceLeft = left;
    m_sliceRight = right;
    m_sliceTop = top;
    m_sliceBottom = bottom;
}

void NineSlicePanelComponent::setSize(int width, int height) {
    m_width = width;
    m_height = height;
}

std::shared_ptr<retronomicon::lib::asset::ImageAsset> NineSlicePanelComponent::getAsset() const {
    return m_imageAsset;
}

int NineSlicePanelComponent::getWidth() const { return m_width; }
int NineSlicePanelComponent::getHeight() const { return m_height; }
int NineSlicePanelComponent::getLeft() const { return m_sliceLeft; }
int NineSlicePanelComponent::getRight() const { return m_sliceRight; }
int NineSlicePanelComponent::getTop() const { return m_sliceTop; }
int NineSlicePanelComponent::getBottom() const { return m_sliceBottom; }

void NineSlicePanelComponent::render(SDL_Renderer* renderer) {
    if (!m_imageAsset || !m_imageAsset->getTexture()) return;

    // Optional: integrate with a TransformComponent if available
    int x = 0;
    int y = 0;

    if (owner) {
        if (auto transform = owner->getComponent<retronomicon::lib::core::TransformComponent>()) {
            x = transform->getX() - (m_width * transform->getAnchorX());
            y = transform->getY() - (m_height * transform->getAnchorY());
        }
    }


    int texW = m_imageAsset->getWidth();
    int texH = m_imageAsset->getHeight();

    int centerW = texW - m_sliceLeft - m_sliceRight;
    int centerH = texH - m_sliceTop - m_sliceBottom;

    int targetCenterW = m_width - m_sliceLeft - m_sliceRight;
    int targetCenterH = m_height - m_sliceTop - m_sliceBottom;

    SDL_Rect src[9] = {
        { 0, 0, m_sliceLeft, m_sliceTop },
        { m_sliceLeft, 0, centerW, m_sliceTop },
        { m_sliceLeft + centerW, 0, m_sliceRight, m_sliceTop },
        { 0, m_sliceTop, m_sliceLeft, centerH },
        { m_sliceLeft, m_sliceTop, centerW, centerH },
        { m_sliceLeft + centerW, m_sliceTop, m_sliceRight, centerH },
        { 0, m_sliceTop + centerH, m_sliceLeft, m_sliceBottom },
        { m_sliceLeft, m_sliceTop + centerH, centerW, m_sliceBottom },
        { m_sliceLeft + centerW, m_sliceTop + centerH, m_sliceRight, m_sliceBottom }
    };

    SDL_Rect dst[9] = {
        { x, y, m_sliceLeft, m_sliceTop },
        { x + m_sliceLeft, y, targetCenterW, m_sliceTop },
        { x + m_sliceLeft + targetCenterW, y, m_sliceRight, m_sliceTop },
        { x, y + m_sliceTop, m_sliceLeft, targetCenterH },
        { x + m_sliceLeft, y + m_sliceTop, targetCenterW, targetCenterH },
        { x + m_sliceLeft + targetCenterW, y + m_sliceTop, m_sliceRight, targetCenterH },
        { x, y + m_sliceTop + targetCenterH, m_sliceLeft, m_sliceBottom },
        { x + m_sliceLeft, y + m_sliceTop + targetCenterH, targetCenterW, m_sliceBottom },
        { x + m_sliceLeft + targetCenterW, y + m_sliceTop + targetCenterH, m_sliceRight, m_sliceBottom }
    };

    SDL_Texture* texture = m_imageAsset->getTexture();
    for (int i = 0; i < 9; ++i) {
        SDL_RenderCopy(renderer, texture, &src[i], &dst[i]);
    }
}

} // namespace retronomicon::lib::ui
