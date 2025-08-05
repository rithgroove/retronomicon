#include "retronomicon/lib/scene/menu_scene.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include <SDL.h>
#include <iostream>
#include "retronomicon/lib/ui/nine_slice_panel_component.h"

namespace retronomicon::lib::scene {
    using retronomicon::lib::core::TransformComponent;
    using retronomicon::lib::ui::NineSlicePanelComponent;
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
            this->m_childEntities.insert(this->m_childEntities.begin(), background); 
            // this->m_childEntities.push_back(background);
        }
        // You could load UI, background, menu music here later
    }

    void MenuScene::createMenu(std::shared_ptr<ImageAsset> nineSliceImage) {
        std::cout << "Creating 9-slice menu panel" << std::endl;

        int windowWidth = Window::getWidth();
        int windowHeight = Window::getHeight();

        // Create entity for panel
        Entity* panel = new Entity();
        panel->setName("menu_panel");

        // Panel size (customize later)
        int panelWidth = 300;
        int panelHeight = 200;

        // Add transform component
        auto* transform = panel->addComponent<TransformComponent>(
            windowWidth / 2.0f, windowHeight / 2.0f, 0.0f, 1.0f, 1.0f);
        transform->setAnchor(0.5f, 0.5f); // Center

        // Add NineSlicePanelComponent
        auto* nineSlice = panel->addComponent<NineSlicePanelComponent>();
        nineSlice->setImageAsset(nineSliceImage);
        nineSlice->setSlices(16, 16, 16, 16); // default slice sizes, adjust as needed
        nineSlice->setSize(panelWidth, panelHeight);

        // Start and add to scene
        panel->start();
        m_childEntities.push_back(panel);
    }


    void MenuScene::shutdown() {
        // Clean up menu-related assets if needed later
    }

}
