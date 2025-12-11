#pragma once
#include <memory>
#include <string>

#include <retronomicon/scene/scene.h>
#include <retronomicon/graphics/renderer/i_renderer.h>
#include <retronomicon/asset/image_asset.h>
#include "retronomicon/manager/texture_manager.h"
#include "retronomicon/engine/game_engine.h"
#include "retronomicon/input/input_map.h"
#include "retronomicon/input/raw_input.h"
#include "retronomicon/asset/sound_effect_asset.h"
#include "retronomicon/asset/font_asset.h"

namespace retronomicon::scene::menu {

    using retronomicon::graphics::renderer::IRenderer;
    using retronomicon::asset::ImageAsset;
    using retronomicon::asset::FontAsset;
    using retronomicon::asset::SoundEffectAsset;
    using retronomicon::entity::Entity;
    using retronomicon::manager::TextureManager;
    using retronomicon::input::InputMap;
    using retronomicon::input::RawInput;
    using retronomicon::engine::GameEngine;

    /**
     * @brief Scene representing the game's main menu UI.
     *
     * Responsibilities:
     *  - Load menu UI assets (backgrounds, fonts, nine-slice panels).
     *  - Instantiate UI entities and systems.
     *  - Handle menu input (navigation, confirm, cancel).
     *  - Trigger scene transitions when the player selects a menu option.
     *
     * This scene relies on the GameEngine for:
     *  - rendering backend access,
     *  - input system access,
     *  - scene transition requests,
     *  - audio playback.
     */
    class MenuScene : public retronomicon::scene::Scene {
    public:
        /**
         * @brief Construct a menu scene with references to engine subsystems.
         *
         * @param gameEngine     Engine instance used for input/render/audio.
         * @param textureManager Texture backend for loading menu textures.
         * @param imagePath      Initial menu background image file path.
         */
        MenuScene(std::shared_ptr<GameEngine> gameEngine,
                  std::shared_ptr<TextureManager> textureManager,
                  const std::string& imagePath);

        /**
         * @brief Called once when the scene becomes active.
         *
         * Initializes entities, loads textures, sets up UI, and binds input.
         */
        void start() override;

        /**
         * @brief Called every frame.
         *
         * @param dt Delta time in seconds.
         *
         * Handles:
         *  - menu animations,
         *  - button navigation,
         *  - skipping intro durations,
         *  - triggering scene transitions.
         */
        void update(float dt) override;

        /**
         * @brief Cleanup when the scene is no longer active.
         *
         * Frees or releases assets, and unregisters any temporary systems.
         */
        void shutdown() override;

        /**
         * @brief Assign a sound effect for menu interactions (hover, confirm, etc.).
         */
        void setSFX(std::shared_ptr<SoundEffectAsset> sfx) { m_sfx = sfx; }

        /**
         * @brief Set the nine-slice panel image used to build the menu UI.
         */
        void setNineSliceImage(const std::string& imagePath) {
            m_nineSliceImage = std::make_shared<ImageAsset>(imagePath);
        }

        /**
         * @brief Set font used for titles, labels, and menu text.
         */
        void setFont(const std::shared_ptr<FontAsset> font) {
            m_font = font;
        }

    protected:
        /**
         * @brief Create all ECS entities required by the menu.
         *
         * Includes background, UI panels, text elements, etc.
         */
        void initiateEntities();

        /**
         * @brief Register systems or logic needed by the menu scene.
         */
        void initiateSystems();

        /**
         * @brief Build the nine-slice menu panel(s).
         *
         * Used for scalable menu backgrounds or window frames.
         */
        void buildNineSliceMenu();

        // --------------------------------------------------------------------
        // Scene Resources & Dependencies
        // --------------------------------------------------------------------
        std::shared_ptr<GameEngine>     m_gameEngine;      ///< Engine access (input, audio, scene switching).
        std::shared_ptr<IRenderer>      m_renderer;        ///< Cached renderer from RenderManager.
        std::shared_ptr<TextureManager> m_textureManager;  ///< Texture creation backend.

        // --------------------------------------------------------------------
        // Assets
        // --------------------------------------------------------------------
        std::shared_ptr<ImageAsset>     m_backgroundImage; ///< Menu background image.
        std::shared_ptr<ImageAsset>     m_nineSliceImage;  ///< Scalable panel image.
        std::shared_ptr<FontAsset>      m_font;            ///< Menu UI font.
        std::shared_ptr<SoundEffectAsset> m_sfx;           ///< UI sound effects.

        // --------------------------------------------------------------------
        // Scene Entities
        // --------------------------------------------------------------------
        std::shared_ptr<Entity> m_backgroundEntity; ///< Background sprite entity.

        // --------------------------------------------------------------------
        // Input
        // --------------------------------------------------------------------
        std::shared_ptr<InputMap> m_inputMap; ///< Input bindings for menu actions.
        std::shared_ptr<RawInput> m_rawInput; ///< Raw hardware input.

        // --------------------------------------------------------------------
        // Internal State
        // --------------------------------------------------------------------
        std::string m_imagePath; ///< Initial background file path.
        std::string m_nextScene; ///< Scene to transition to when selection is confirmed.

        float m_elapsedTime = 0.0f; ///< Time accumulator for intro durations or animations.
        float m_duration    = 3.0f; ///< Auto-advance duration or animation time.

        bool m_skipRequested = false; ///< True when user requests to skip intro/wait period.
    };

} // namespace retronomicon::scene::menu
