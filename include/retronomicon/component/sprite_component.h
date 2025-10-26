#pragma once

#include <memory>

#include "component.h"
#include "transform_component.h"
#include "animation_component.h"
#include "renderable.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/graphics/texture.h"
#include "retronomicon/math/rect.h"
#include "retronomicon/manager/texture_manager.h"
// Forward declarations
// namespace retronomicon::core::ecs { 
//     class TransformComponent; 
// }
// namespace retronomicon::animation { 
//     class AnimationComponent; 
// }

namespace retronomicon::component {
    using retronomicon::math::Rect;
    using retronomicon::graphics::Texture;
    using retronomicon::manager::TextureManager;
    /**
     * @brief A drawable sprite that optionally supports animation.
     *
     * The sprite uses its owner's TransformComponent for position, scale,
     * rotation, and anchor. If an AnimationComponent is present, it uses
     * the current animation frame; otherwise, it renders the static image.
     */
    class SpriteComponent : public Component, public Renderable {
    public:
        explicit SpriteComponent(std::shared_ptr<asset::ImageAsset> imageAsset);
        ~SpriteComponent() override = default;

        void start() override;                ///< Cache Transform + Animation
        void update(float dt) override;       ///< Hook for animation triggers
        void render(std::shared_ptr<IRenderer> renderer)  override;               ///< Delegates to backend renderer

        /// Swap sprite image at runtime (e.g., skin or asset change)
        void changeAsset(std::shared_ptr<asset::ImageAsset> asset);
        void generateTexture(std::shared_ptr<TextureManager> textureManager);
    private:
        std::shared_ptr<asset::ImageAsset> m_image = nullptr;
        std::shared_ptr<Texture> m_texture = nullptr; ///< Backend texture

        // Cached pointers (owned by ECS, safe to cache)
        std::shared_ptr<TransformComponent> m_transform = nullptr;
        std::shared_ptr<AnimationComponent> m_animation = nullptr;
    };

} // namespace retronomicon::graphics
