#pragma once

#include "retronomicon/lib/core/component.h"
#include "retronomicon/lib/core/renderable.h"
#include "retronomicon/lib/asset/image_asset.h"
#include <memory>

namespace retronomicon::lib::ui {

/**
 * @brief A component that renders a 9-slice panel, typically used for scalable UI boxes.
 */
class NineSlicePanelComponent : public retronomicon::lib::core::Component,
                                 public retronomicon::lib::core::Renderable {
public:
    NineSlicePanelComponent();
    ~NineSlicePanelComponent() override = default;

    void setImageAsset(std::shared_ptr<retronomicon::lib::asset::ImageAsset> asset);
    void setSlices(int left, int right, int top, int bottom);
    void setSize(int width, int height);

    std::shared_ptr<retronomicon::lib::asset::ImageAsset> getAsset() const;
    int getWidth() const;
    int getHeight() const;
    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;

    /**
     * @brief Called by the RenderSystem or manual calls for rendering.
     */
    void render(SDL_Renderer* renderer) override;

private:
    std::shared_ptr<retronomicon::lib::asset::ImageAsset> m_imageAsset;

    int m_sliceLeft = 0;
    int m_sliceRight = 0;
    int m_sliceTop = 0;
    int m_sliceBottom = 0;

    int m_width = 0;
    int m_height = 0;
};

} // namespace retronomicon::lib::ui
