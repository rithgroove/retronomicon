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

    class NineSlicePanelComponent : public Component,
                                    public Renderable {
    public:
        NineSlicePanelComponent(std::shared_ptr<ImageAsset> imageAsset);
        ~NineSlicePanelComponent() override = default;

        void start() override;
        void render(std::shared_ptr<IRenderer> renderer) override;

        void setSlices(int left, int right, int top, int bottom);
        void setSize(int width, int height);

        void setAsset(std::shared_ptr<ImageAsset> asset);
        void generateTexture(std::shared_ptr<TextureManager> textureManager);

    private:
        std::shared_ptr<ImageAsset> m_image = nullptr;
        std::shared_ptr<Texture>    m_texture = nullptr;

        std::shared_ptr<TransformComponent>  m_transform = nullptr;

        int m_sliceLeft   = 0;
        int m_sliceRight  = 0;
        int m_sliceTop    = 0;
        int m_sliceBottom = 0;

        int m_width  = 0;
        int m_height = 0;
    };

}
