#include "retronomicon/lib/core/scene.h"
#include <algorithm> // for std::remove
#include <iostream>
/**
 * @brief namespace for scene
 */
namespace retronomicon::scene {
    /***************************** Constructor *****************************/

    /**
     * @brief constructor with name
     * 
     * @param name will be passed to entity parent class
     */
    Scene::Scene(const std::string& name)
        : Entity(name), m_isInitialized(false), m_isActive(false), m_requiresReset(false) {
    }

    /***************************** Destructor *****************************/

    /**
     * @brief overidable destructor. calls shutdown()
     */
    Scene::~Scene() {
        shutdown();
    }

    /***************************** Main Methods *****************************/
    
    /**
     * @brief start function (used to initialize stuff)
     * also call Entity::start() to reuse
     */    
    void Scene::start(){
        // call base class version
        Entity::start();  // <-- "super.start()" equivalent
        m_requiresReset = false;
    }

    /**
     * @brief loop system for update
     * 
     * @parameter dt delta time since last update
     */    
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

    /**
     * @brief method to shutdown and delete all child entities
     */
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

    /**
     * @brief method to shutdown and restart
     */
    void Scene::reset() {
        shutdown();
        start();
    }


    void Scene::addSystem(std::unique_ptr<System> system) {
        m_systems.push_back(std::move(system));
    }
}
