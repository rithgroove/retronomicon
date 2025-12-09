#pragma once

#include <memory>

#include "component.h"
#include "transform_component.h"
#include "animation_component.h"
#include "bound_component.h"
#include "renderable.h"
#include "retronomicon/asset/image_asset.h"
#include "retronomicon/graphics/texture.h"
#include "retronomicon/math/rect.h"
#include "retronomicon/manager/texture_manager.h"

namespace retronomicon::component {

    using retronomicon::math::Rect;
    using retronomicon::graphics::Texture;
    using retronomicon::manager::TextureManager;

    /**
     * @brief Renders a static or animated sprite.
     *
     * Responsibilities:
     *  - Draws a texture at the entity's position, using TransformComponent.
     *  - Uses BoundComponent for source rect (cropping, collision size).
     *  - If AnimationComponent is present, retrieves the current frame.
     *
     * Typical flow:
     *  1. `start()` caches Transform, Bound, Animation components.
     *  2. `generateTexture()` is called when ImageAsset is ready.
     *  3. `update()` may advance animation events (optional).
     *  4. `render()` draws the sprite using the backend renderer.
     */
    class SpriteComponent : public Component, public Renderable {
    public:
        /**
         * @brief Construct with a given image asset.
         *
         * @param imageAsset The image used for rendering (static or animated atlas).
         */
        explicit SpriteComponent(std::shared_ptr<asset::ImageAsset> imageAsset);

        ~SpriteComponent() override = default;

        /**
         * @brief Initialize and cache supporting components.
         *
         * Looks up:
         *  - TransformComponent
         *  - BoundComponent (if present)
         *  - AnimationComponent (optional)
         */
        void start() override;

        /**
         * @brief Optional update hook for animation-driven logic.
         *
         * @param dt Delta time in seconds.
         */
        void update(float dt) override;

        /**
         * @brief Render the sprite using the backend renderer.
         *
         * If AnimationComponent exists, uses its current frame rect.
         * Otherwise, draws the entire texture or bound-defined region.
         *
         * @param renderer Renderer backend (SDL/OpenGL/…).
         */
        void render(std::shared_ptr<IRenderer> renderer) override;

        /**
         * @brief Change the sprite's image at runtime.
         *
         * Does not automatically refresh texture — call `generateTexture()`.
         *
         * @param asset New ImageAsset to use.
         */
        void changeAsset(std::shared_ptr<asset::ImageAsset> asset);

        /**
         * @brief Convert the ImageAsset into a backend-usable texture.
         *
         * Should be called once the TextureManager is available, usually
         * during scene load or asset warm-up.
         *
         * @param textureManager Backend texture manager.
         */
        void generateTexture(std::shared_ptr<TextureManager> textureManager);

    private:
        /// Raw 2D image asset.
        std::shared_ptr<asset::ImageAsset> m_image = nullptr;

        /// Backend native texture (GL texture, SDL texture, etc.).
        std::shared_ptr<Texture> m_texture = nullptr;

        // Cached ECS-owned components
        std::shared_ptr<TransformComponent>  m_transform = nullptr; ///< Position/rotation/scale data.
        std::shared_ptr<BoundComponent>      m_bound = nullptr;     ///< Optional cropping/size info.
        std::shared_ptr<AnimationComponent>  m_animation = nullptr; ///< Optional animation driver.
    };

} // namespace retronomicon::component
