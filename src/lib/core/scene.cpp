#include "retronomicon/lib/core/scene.h"
#include <algorithm> // for std::remove
#include <iostream>
namespace retronomicon::lib::core {

    Scene::Scene(const std::string& name)
        : Entity(name), m_isInitialized(false), m_isActive(false), m_requiresReset(false) {
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
            system->render(this);
        }
    }

    void Scene::shutdown() {
        // for (auto& system : m_systems) {
        //     system->shutdown(this);
        // }

        for (auto* obj : m_childEntities) {
            delete obj;  // future: switch to smart pointers
        }

        m_childEntities.clear();
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
