#include <SDL.h>
#include <iostream>

#include "retronomicon/lib/scene/menu/menu_scene.h"
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/graphic/window.h"
#include "retronomicon/lib/core/transform_component.h"
#include "retronomicon/lib/graphic/sprite_component.h"
#include "retronomicon/lib/ui/text_label_component.h"
#include "retronomicon/lib/ui/nine_slice_panel_component.h"

namespace retronomicon::lib::scene::menu {
    using retronomicon::lib::core::TransformComponent;
    using retronomicon::lib::ui::NineSlicePanelComponent;
    using retronomicon::lib::ui::TextLabelComponent;
    using retronomicon::lib::graphic::SpriteComponent;
    using retronomicon::lib::graphic::Window;
    MenuScene::MenuScene()
        : Scene("menu_scene") {}

    MenuScene::MenuScene(GameEngine* engine, std::shared_ptr<ImageAsset> backgroundImage,std::shared_ptr<FontAsset> fontAsset)
        : Scene("menu_scene"),m_gameEngine(engine),m_backgroundImage(backgroundImage),m_fontAsset(fontAsset) {
            std::cout<<"Masuk constructor yang pake background Image"<<std::endl;
        }


    void MenuScene::init() {
        m_timer = 0.0f;

        std::cout<<"Masuk init"<<std::endl;

        // You could load UI, background, menu music here later
    }


    InputMap* SplashScene::generateInputMap(){
        std::cout << "[Splash Scene] setup input map" <<std::endl;
        InputMap* inputMap = new InputMap();
        inputMap->bindAction(SDL_SCANCODE_SPACE, "confirm");
        inputMap->bindAction(SDL_SCANCODE_RETURN, "confirm");
        inputMap->bindAction(SDL_SCANCODE_A, "left");
        inputMap->bindAction(SDL_SCANCODE_W, "up");
        inputMap->bindAction(SDL_SCANCODE_S, "down");
        inputMap->bindAction(SDL_SCANCODE_D, "right");
        inputMap->bindAction(SDL_SCANCODE_ESCAPE,"quit");
        return inputMap;        
    }

    void SplashScene::setupSystem(){
        //setup input map and update inputstate to use thesep
        auto* inputState = m_engine->getInputState();
        inputState->setInputMap(this->generateInputMap());

        // setup systems
        std::cout << "[Splash Scene] setup systems" <<std::endl;

        // setup animation system used for timer until changing to next scene
        // this->addSystem(std::make_unique<AnimationSystem>());
        // setup render system used to draw to screen
        this->addSystem(std::make_unique<RenderSystem>(m_renderer));
        // setup scene change system to trigger scene change to the next one
        // this->addSystem(std::make_unique<SceneChangeSystem>(m_engine));
        // setup input system to skip to next scene
        this->addSystem(std::make_unique<InputSystem>(inputState));
    }

    void MenuScene::createMenu(std::shared_ptr<ImageAsset> nineSliceImage = nullptr,std::shared_ptr<FontAsset> fontAsset = nullptr) {
        if (nineSliceImage){
            this->m_nineSliceImage = nineSliceImage;
        }
        if (fontAsset){
            this->m_fontAsset = fontAsset;
        }
        if (m_backgroundImage){

            std::cout<<"Masuk init yang pake background Image"<<std::endl;
            std::string name = "background";
            Entity* background = new Entity(name);
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
            this->addChildEntity(background);
            // this->m_childEntities.push_back(background);
        }


        std::cout << "Creating 9-slice menu panel" << std::endl;

        int windowWidth = Window::getWidth();
        int windowHeight = Window::getHeight();

        // Create entity for panel
        std::string name = "nine slice panel";

        Entity* panel = new Entity(name);
        panel->setName("menu_panel");

        // Panel size (customize later)
        int panelWidth = 300;
        int panelHeight = 200;

        // Add transform component
        auto* transform = panel->addComponent<TransformComponent>(
            windowWidth / 2.0f, windowHeight - 200, 0.0f, 1.0f, 1.0f);
        transform->setAnchor(0.5f, 0.5f); // Center

        // Add NineSlicePanelComponent
        auto* nineSlice = panel->addComponent<NineSlicePanelComponent>();
        nineSlice->setImageAsset(this->m_nineSliceImage);
        nineSlice->setSlices(16, 16, 16, 16); // default slice sizes, adjust as needed
        nineSlice->setSize(panelWidth, panelHeight);
        panel->start();

        auto* m_splashChangeComponent = this->addComponent<SceneChangeComponent>("Splash");
        // Create entity for panel
        Entity* newGameOption = new Entity("newGameOption");
        SDL_Color gray = { 70, 70, 70, 255};
        newGameOption->addComponent<TextLabelComponent>("New Game",this->m_fontAsset,gray,600,50,5,5);
        newGameOption->addComponent<TransformComponent>(250,400,1.0f,1.0f);
        panel->addChildEntity(newGameOption);

        panel->setName("menu_panel");
        //create new game options:
        m_options.emplace_back("New Game", m_splashChangeComponent) ;
        newGameOption->start();

        // Start and add to scene
        this->addChildEntity(panel);
        std::cout<<"Selesai"<<std::endl;
    }


    void MenuScene::shutdown() {
        // Clean up menu-related assets if needed later
    }

}
