#pragma once

#include <string>
#include <memory>
#include <vector>
#include "retronomicon/entity/entity.h"
#include "retronomicon/system/system.h"
#include "retronomicon/manager/render_manager.h"
/**
 * @brief namespace for scene
 */
namespace retronomicon::entity::scene {
    using retronomicon::entity::Entity;
    using retronomicon::system::System;
    using retronomicon::manager::RenderManager;
    /*
     * @brief abstract scene class
     */
    class Scene : public Entity {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief constructor with name
             * 
             * @param name will be passed to entity parent class
             */
            Scene(const std::string& name);

            /***************************** Destructor *****************************/

            /**
             * @brief overidable destructor. calls shutdown()
             */
            virtual ~Scene();

            /***************************** Main Methods *****************************/
            
            /**
             * @brief start function (used to initialize stuff)
             * also call Entity::start() to reuse
             */  
            virtual void start() override;    

            /**
             * @brief loop system for update
             * 
             * @parameter dt delta time since last update
             */    
            virtual void update(float dt);

            /**
             * @brief render method call all system render (not yet efficient enough)
             */    
            virtual void render();

            /**
             * @brief method to shutdown and delete all child entities
             */
            virtual void shutdown();

            /**
             * @brief method to shutdown and restart
             */
            virtual void reset();

            void setRequiresReset(bool requireReset){
                m_requiresReset = requireReset;
            }

            bool isRequiresReset(){
                return m_requiresReset;
            }
            /***************************** Getter *****************************/
            /**
             * @brief method to check if scene is active. This is useful if we 
             * layer scene on top of each other. Some system will check for this
             * and update the active scene only (like menu scene)
             * 
             * @return true if active
             */
            bool isActive() const { return m_isActive; }

            /***************************** Setter *****************************/
            /**
             * @brief method to register a system to this scene.
             * Make sure the order of system inserted to this scene is correct 
             * 
             * @param a system to be registered
             */
            void addSystem(std::unique_ptr<System> system);

        protected:
            /***************************** Attribute *****************************/
            bool m_isActive = false; // used in some systems to trigger only active scene (basically so we could include scene inside scene)
            bool m_requiresReset = false;
            // InputMap* m_inputMap = nullptr;
            
            std::vector<std::unique_ptr<System>> m_systems;
            RenderManager m_renderManager; 
    };

}
