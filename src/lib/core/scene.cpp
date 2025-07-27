#include "retronomicon/lib/core/scene.h"
#include <algorithm> // for std::remove

namespace retronomicon::lib::core {

    Scene::Scene(const std::string& name)
        : m_name(name), m_isInitialized(false), m_isActive(false), m_requiresReset(false) {
    }

    Scene::~Scene() {
        shutdown();
    }

    void Scene::init() {
        if (m_isInitialized) return;
        // for (auto& system : m_systems) {
        //     system->init(this);
        // }
        m_isInitialized = true;
        m_requiresReset = false;
    }

    void Scene::update(float dt) {
        for (auto& system : m_systems) {
            system->update(dt, this);
        }
    }

    void Scene::render() {
        for (auto& system : m_systems) {
            system->render(m_gameObjects);
        }
    }

    void Scene::shutdown() {
        // for (auto& system : m_systems) {
        //     system->shutdown(this);
        // }

        for (auto* obj : m_gameObjects) {
            delete obj;  // future: switch to smart pointers
        }

        m_gameObjects.clear();
        m_isInitialized = false;
    }

    void Scene::reset() {
        shutdown();
        init();
    }


    void Scene::addSystem(std::unique_ptr<System> system) {
        m_systems.push_back(std::move(system));
    }
}
