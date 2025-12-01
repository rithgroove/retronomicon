#include "retronomicon/component/nine_slice_panel_component.h"
#include "retronomicon/entity/entity.h"
#include <iostream>

namespace retronomicon::component {
    using retronomicon::entity::Entity;
    NineSlicePanelComponent::NineSlicePanelComponent() = default;

    void NineSlicePanelComponent::setImageAsset(std::shared_ptr<ImageAsset> asset) {
        m_imageAsset = std::move(asset);
    }

    void NineSlicePanelComponent::setSlices(int left, int right, int top, int bottom) {
        m_sliceLeft   = left;
        m_sliceRight  = right;
        m_sliceTop    = top;
        m_sliceBottom = bottom;
    }

    void NineSlicePanelComponent::start() {
        m_transform = getOwner()->getComponent<TransformComponent>();

        if (!m_transform) {
            std::cerr << "[NineSlicePanelComponent] Missing TransformComponent on entity.\n";
        }
    }

    void NineSlicePanelComponent::setSize(int width, int height) {
        m_width  = width;
        m_height = height;
    }

    Rect NineSlicePanelComponent::getSize() {
        if (!m_transform) {
            return Rect(0, 0, m_width, m_height);
        }

        float scaledW = m_width  * m_transform->getScaleX();
        float scaledH = m_height * m_transform->getScaleY();

        return Rect(0, 0, scaledW, scaledH);
    }

    void NineSlicePanelComponent::render(graphics::IRenderer& renderer) {
        // Core does NOT render anything — it only forwards the call.
        // Backend renderer decides how to render this component.

        renderer.renderNineSlicePanel(*this, m_transform);
    }

} // namespace retronomicon::component
