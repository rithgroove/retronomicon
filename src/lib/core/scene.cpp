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
            system->update(dt, m_gameObjects);
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

    Entity* Scene::createGameObject(const std::string& name) {
        Entity* obj = new Entity(); // optional: set name if Entity supports it
        m_gameObjects.push_back(obj);
        return obj;
    }

    void Scene::removeGameObject(Entity* object) {
        auto it = std::remove(m_gameObjects.begin(), m_gameObjects.end(), object);
        if (it != m_gameObjects.end()) {
            delete *it;
            m_gameObjects.erase(it, m_gameObjects.end());
        }
    }

    void Scene::addSystem(std::unique_ptr<System> system) {
    }
}
