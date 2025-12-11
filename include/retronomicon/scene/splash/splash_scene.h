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

namespace retronomicon::scene::splash {

    using retronomicon::graphics::renderer::IRenderer;
    using retronomicon::asset::ImageAsset;
    using retronomicon::entity::Entity;
    using retronomicon::manager::TextureManager;
    using retronomicon::input::InputMap;
    using retronomicon::input::RawInput;
    using retronomicon::engine::GameEngine;
    using retronomicon::asset::SoundEffectAsset;

    /**
     * @brief Simple timed splash screen for logos or branding.
     *
     * Responsibilities:
     *  - Display a static logo or splash image.
     *  - Optionally play a sound effect.
     *  - Allow skipping via user input.
     *  - Automatically transition to the next scene after a set duration.
     *
     * Typical duration is short (e.g., 3 seconds) with an early skip trigger.
     */
    class SplashScene : public retronomicon::scene::Scene {
    public:
        /**
         * @brief Construct a splash screen scene.
         *
         * @param gameEngine     Engine reference (input, renderer, scene control).
         * @param textureManager Backend for creating GPU textures.
         * @param imagePath      Path to the splash logo image.
         * @param nextScene      Name of the scene to transition to when finished.
         */
        SplashScene(std::shared_ptr<GameEngine> gameEngine,
                    std::shared_ptr<TextureManager> textureManager,
                    const std::string& imagePath,
                    const std::string& nextScene = "");

        /**
         * @brief Called when the scene becomes active.
         *
         * Loads the logo image, creates the logo entity, initializes input,
         * and prepares systems required by the splash screen.
         */
        void start() override;

        /**
         * @brief Per-frame update.
         *
         * @param dt Delta time (seconds).
         *
         * Behavior:
         *  - Increment timer until duration expires.
         *  - If skip is requested (e.g., button press), transition immediately.
         *  - When time is up, automatically change to m_nextScene.
         */
        void update(float dt) override;

        /**
         * @brief Cleanup when leaving the splash screen.
         *
         * Frees temporary entities, unloads textures if needed,
         * and resets pointers to engine modules.
         */
        void shutdown() override;

        /**
         * @brief Assign a sound effect to play when the splash appears.
         */
        void setSFX(std::shared_ptr<SoundEffectAsset> sfx) { m_sfx = sfx; }

    protected:
        /**
         * @brief Instantiate scene entities, such as the logo sprite.
         */
        void initiateEntities();

        /**
         * @brief Register splash-specific systems (input, animation, etc.).
         */
        void initiateSystems();

        // --------------------------------------------------------------------
        // Scene Dependencies
        // --------------------------------------------------------------------
        std::shared_ptr<GameEngine>     m_gameEngine;       ///< Engine context.
        std::shared_ptr<IRenderer>      m_renderer;         ///< Cached renderer.
        std::shared_ptr<TextureManager> m_textureManager;   ///< Texture loader.

        // --------------------------------------------------------------------
        // Assets & Entities
        // --------------------------------------------------------------------
        std::shared_ptr<ImageAsset>     m_logoImage;        ///< Splash logo asset.
        std::shared_ptr<Entity>         m_logoEntity;       ///< Logo entity instance.
        std::shared_ptr<SoundEffectAsset> m_sfx;            ///< Optional sound effect.

        // --------------------------------------------------------------------
        // Input
        // --------------------------------------------------------------------
        std::shared_ptr<InputMap>       m_inputMap;         ///< Input mapping for skip action.
        std::shared_ptr<RawInput>       m_rawInput;         ///< Backend raw input.

        // --------------------------------------------------------------------
        // Splash Logic
        // --------------------------------------------------------------------
        std::string m_imagePath;   ///< Path of logo image used for this splash.
        std::string m_nextScene;   ///< Next scene to transition into.
        float m_elapsedTime = 0.0f;///< Time spent on the splash screen.
        float m_duration    = 3.0f;///< Auto-advance duration in seconds.
        bool m_skipRequested = false; ///< True when user presses skip input.
    };

} // namespace retronomicon::scene::splash
