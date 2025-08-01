#include "retronomicon/lib/scene/splash_scene.h"
#include <SDL_image.h>
#include <SDL_events.h>
#include <iostream> // for debug if needed
#include "retronomicon/lib/scene/scene_change_component.h"
#include "retronomicon/lib/graphic/window.h"


namespace retronomicon::lib::scene {
using retronomicon::lib::graphic::Window;

SplashScene::SplashScene(SDL_Renderer* renderer)
    : Scene("Splash"), m_renderer(renderer) {}

SplashScene::~SplashScene() {
    // unloadAssets();
}

void SplashScene::init() {
    m_timer = 0.0f;
    m_finished = false;
    // loadAssets();
    setInitialized(true);
    setActive(true);
}
void SplashScene::setOnFinish(std::function<void(const std::string&)> callback) {
    m_onFinish = std::move(callback);
}

void SplashScene::update(float dt) {
    handleInput();
    m_timer += dt;
    if (m_timer >= m_duration || m_finished) {
        m_finished = true;

        this->getComponent<SceneChangeComponent>()->triggered = true;
        // Change scene to "Menu" if callback is set
    }

    // std::cout<<"masuk ga?"<< m_timer<<std::endl;
    for (auto& system : m_systems) {
        // std::cout<<"masuk kok"<<std::endl;
        system->update(dt, this);
    }            

}


void SplashScene::shutdown() {
    // unloadAssets();
    setInitialized(false);
    setActive(false);
}

void SplashScene::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    if (m_logoTexture) {
        int w, h;
        SDL_QueryTexture(m_logoTexture, nullptr, nullptr, &w, &h);
        SDL_Rect dst = { (Window::getWidth() - w) / 2, (Window::getHeight() - h) / 2, w, h };
        SDL_RenderCopy(m_renderer, m_logoTexture, nullptr, &dst);
    }

    SDL_RenderPresent(m_renderer);
}

bool SplashScene::isFinished() const {
    return m_finished;
}

void SplashScene::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT ||
            event.type == SDL_KEYDOWN ||
            event.type == SDL_MOUSEBUTTONDOWN) {
            m_finished = true;
        }
    }
}

void SplashScene::setImage(SDL_Texture* texture){
    m_logoTexture = texture;
}

} // namespace retronomicon::platformer::scene
