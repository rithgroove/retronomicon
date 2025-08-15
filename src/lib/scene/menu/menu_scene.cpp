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

    MenuScene::MenuScene(
        GameEngine* engine, 
        std::shared_ptr<ImageAsset> backgroundImage,
        std::shared_ptr<ImageAsset> nineSliceImage,
        std::shared_ptr<FontAsset> fontAsset)
            : Scene("menu_scene"),
              m_gameEngine(engine),
              m_backgroundImage(backgroundImage),
              m_nineSliceImage(nineSliceImage),
              m_fontAsset(fontAsset) 
        {
            std::cout<<"[MenuScene] contruct menu scene will full parameters"<<std::endl;
        }


    void MenuScene::init() {
        std::cout<<"Masuk init"<<std::endl;
        this->setupSystem();
        this->buildBackgroundImage();
        this->buildNineSliceMenu();
        // You could load UI, background, menu music here later
    }

    void MenuScene::buildBackgroundImage(){
        if (m_backgroundImage){
            std::cout<<"[Menu Scene] setup background image"<<std::endl;
            Entity* background = new Entity("background");

            // -------- recalculate scaling based on windows width -----
            int imageWidth = m_backgroundImage->getWidth();
            int imageHeight = m_backgroundImage->getHeight();
            int windowWidth = Window::getWidth();
            int windowHeight = Window::getHeight();

            float scaling = float(windowWidth) / float(imageWidth);
            if (float(windowHeight)/float(imageHeight)> scaling){
                scaling = float(windowHeight)/float(imageHeight);
            }

            //-------- Build Transform Component for background ---------------
            TransformComponent* backgroundTransform = background->addComponent<TransformComponent>(windowWidth/2.0,windowHeight/2.0,0.0f,scaling,scaling);
            backgroundTransform->setAnchor(0.5f,0.5f);
            backgroundTransform->setRotation(0.0f);

            //-------- Build Sprite Component for background ---------------
            SpriteComponent *backgroundSprite = background->addComponent<SpriteComponent>(m_backgroundImage);

            //--------- initiate background -------------------
            background->start();

            //--------- add background as child entity -------------------
            this->addChildEntity(background);
            // this->m_childEntities.push_back(background);
        }
    }

    void MenuScene::buildNineSliceMenu(){
        if (m_nineSliceImage){
            std::cout << "[Menu Scene] Creating 9-slice menu panel" << std::endl;


            // -------------- Create entity for panel------------------
            Entity* panel = new Entity("nine slice panel");

            // ----------------- Panel size (customize later)--------------------
            int windowWidth = Window::getWidth();
            int windowHeight = Window::getHeight();
            int panelWidth = windowWidth/2;
            int panelHeight = windowHeight/2;

            // -------------- Add transform component -----------------------
            auto* transform = panel->addComponent<TransformComponent>(
                windowWidth / 2.0f, windowHeight - 100, 0.0f, 1.0f, 1.0f); //100 pixel from below
            transform->setAnchor(0.5f, 1.0f); // anchor bottom middle
            transform->setRotation(0.0f); // anchor bottom middle

            // --------------- Add NineSlicePanelComponent ----------------------
            auto* nineSlice = panel->addComponent<NineSlicePanelComponent>();
            nineSlice->setImageAsset(this->m_nineSliceImage);
            nineSlice->setSlices(16, 16, 16, 16); // default slice sizes, adjust as needed
            nineSlice->setSize(panelWidth, panelHeight);

            //--------- initiate panel -------------------
            panel->start();

            //--------- add nine slice panel as child entity -------------------
            this->addChildEntity(panel);



        // auto* m_splashChangeComponent = this->addComponent<SceneChangeComponent>("Splash");
        // // Create entity for panel
        // Entity* newGameOption = new Entity("newGameOption");
        // SDL_Color gray = { 70, 70, 70, 255};
        // newGameOption->addComponent<TextLabelComponent>("New Game",this->m_fontAsset,gray,600,50,5,5);
        // newGameOption->addComponent<TransformComponent>(250,400,1.0f,1.0f);
        // panel->addChildEntity(newGameOption);

        // panel->setName("menu_panel");
        // //create new game options:
        // m_options.emplace_back("New Game", m_splashChangeComponent) ;
        // newGameOption->start();


        }
    }


    InputMap* MenuScene::generateInputMap(){
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

    void MenuScene::setupSystem(){
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

    void MenuScene::shutdown() {
        // Clean up menu-related assets if needed later
    }

}
