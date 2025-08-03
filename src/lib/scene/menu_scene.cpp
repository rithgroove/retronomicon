#include "retronomicon/lib/scene/menu_scene.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include <SDL.h>
#include <iostream>

namespace retronomicon::lib::scene {
    using retronomicon::lib::core::TransformComponent;
    using retronomicon::lib::graphic::SpriteComponent;
    using retronomicon::lib::graphic::Window;
    MenuScene::MenuScene()
        : Scene("menu_scene") {}

    MenuScene::MenuScene(std::shared_ptr<ImageAsset> backgroundImage)
        : Scene("menu_scene"),m_backgroundImage(backgroundImage) {
            std::cout<<"Masuk constructor yang pake background Image"<<std::endl;

        }

    void MenuScene::init() {
        m_timer = 0.0f;

        std::cout<<"Masuk init"<<std::endl;
        if (m_backgroundImage){

            std::cout<<"Masuk init yang pake background Image"<<std::endl;
            Entity* background = new Entity();
            background->setName("menu_scene_bg");
            int imageWidth = m_backgroundImage->getWidth();
            int imageHeight = m_backgroundImage->getHeight();
            int windowWidth = Window::getWidth();
            int windowHeight = Window::getHeight();

            float scaling = float(windowWidth) / float(imageWidth);
            if (float(windowHeight)/float(imageHeight)> scaling){
                scaling = float(windowHeight)/float(imageHeight);
            }


            TransformComponent* backgroundTransform = background->addComponent<TransformComponent>(windowWidth/2.0,windowHeight/2.0,0.0f,scaling,scaling);
            backgroundTransform->setAnchor(0.5f,0.5f);
            SpriteComponent *backgroundSprite = background->addComponent<SpriteComponent>(m_backgroundImage);
            background->start();
            this->m_childEntities.push_back(background);
        }
        // You could load UI, background, menu music here later
    }

    // void MenuScene::update(float dt) {
    //     m_timer += dt;

    //     // Just auto-proceed after 3 seconds for now (like pressing Start)
    //     // if (m_timer > 3.0f && !hasComponent<SceneChangeComponent>()) {
    //     //     addComponent<SceneChangeComponent>("level_1_1_scene");
    //     // }
    // }

    // void MenuScene::render() {
    //     // Optional: just change background color to make it obvious we're in MenuScene
    //     // auto window = Window::get();
    //     // SDL_SetRenderDrawColor(window->getRenderer(), 0, 0, 100, 255); // Dark Blue
    //     // SDL_RenderClear(window->getRenderer());

    //     // TODO: Draw menu items with a future UI system
    // }

    void MenuScene::shutdown() {
        // Clean up menu-related assets if needed later
    }

}
