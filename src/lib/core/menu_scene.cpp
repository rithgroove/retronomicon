#include "retronomicon/lib/core/menu_scene.h"
#include "retronomicon/lib/core/scene_change_component.h"
#include "retronomicon/lib/graphic/window.h"
#include <SDL.h>

namespace retronomicon::lib::core {

    MenuScene::MenuScene()
        : Scene("menu_scene") {}

    void MenuScene::init() {
        m_timer = 0.0f;
        // You could load UI, background, menu music here later
    }

    void MenuScene::update(float dt) {
        m_timer += dt;

        // Just auto-proceed after 3 seconds for now (like pressing Start)
        if (m_timer > 3.0f && !hasComponent<SceneChangeComponent>()) {
            addComponent<SceneChangeComponent>("level_1_1_scene");
        }
    }

    void MenuScene::render() {
        // Optional: just change background color to make it obvious we're in MenuScene
        // auto window = Window::get();
        // SDL_SetRenderDrawColor(window->getRenderer(), 0, 0, 100, 255); // Dark Blue
        // SDL_RenderClear(window->getRenderer());

        // TODO: Draw menu items with a future UI system
    }

    void MenuScene::shutdown() {
        // Clean up menu-related assets if needed later
    }

}
