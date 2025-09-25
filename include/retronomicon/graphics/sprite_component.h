#pragma once

#include <memory>

#include "retronomicon/core/ecs/component.h"
#include "retronomicon/core/ecs/transform_component.h"
#include "retronomicon/animation/animation_component.h"
#include "retronomicon/core/ecs/renderable.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/graphics/texture.h"
#include "retronomicon/core/math/rect.h"
// Forward declarations
// namespace retronomicon::core::ecs { 
//     class TransformComponent; 
// }
// namespace retronomicon::animation { 
//     class AnimationComponent; 
// }

namespace retronomicon::graphics {
    using retronomicon::core::math::Rect;

    /**
     * @brief A drawable sprite that optionally supports animation.
     *
     * The sprite uses its owner's TransformComponent for position, scale,
     * rotation, and anchor. If an AnimationComponent is present, it uses
     * the current animation frame; otherwise, it renders the static image.
     */
    class SpriteComponent : public core::ecs::Component, public core::ecs::Renderable {
    public:
        explicit SpriteComponent(std::shared_ptr<asset::ImageAsset> imageAsset);
        ~SpriteComponent() override = default;

        void start() override;                ///< Cache Transform + Animation
        void update(float dt) override;       ///< Hook for animation triggers
        void render() override;               ///< Delegates to backend renderer

        /// Swap sprite image at runtime (e.g., skin or asset change)
        void changeAsset(std::shared_ptr<asset::ImageAsset> asset);

    private:
        std::shared_ptr<asset::ImageAsset> m_image = nullptr;
        std::unique_ptr<Texture> m_texture = nullptr; ///< Backend texture

        // Cached pointers (owned by ECS, safe to cache)
        core::ecs::TransformComponent* m_transform = nullptr;
        animation::AnimationComponent* m_animation = nullptr;
    };

} // namespace retronomicon::graphics
