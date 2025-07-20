#include "retronomicon/lib/core/scene.h"

namespace retronomicon::lib::core {

    Scene::Scene(const std::string& name){
        m_name = name;
    }

    Scene::~Scene() {
        shutdown();
    }

    void Scene::init() {
        // Optional: initialize systems
        // for (auto& system : _systems) {
        //     system->init();
        // }
    }

    void Scene::update(float dt) {
        for (auto &system : m_systems){
            system->update(dt,m_gameObjects);
        }
        // for (auto& system : _systems) {
        //     system->update(dt, _gameObjects);
        // }
    }

    void Scene::render() {
        for (auto &system : m_systems){
            system->render(m_gameObjects);
        }
    }

    void Scene::shutdown() {
        m_gameObjects.clear();
        // _systems.clear();
    }

    std::string Scene::getName() const {
        return m_name;
    }

    Entity* Scene::createGameObject(const string& name) {
        Entity* obj = new Entity();
        m_gameObjects.push_back(obj);
        return obj;
    }

    void Scene::removeGameObject(Entity* object) {
        // _gameObjects.erase(std::remove(_gameObjects.begin(), _gameObjects.end(), object), _gameObjects.end());
    }

    void Scene::addSystem(System* system) {
        m_systems.push_back(system);
    }

}