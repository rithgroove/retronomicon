#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <string>
#include "retronomicon/lib/core/entity.h"
#include "component.h"

using namespace std;
/**
 * @brief The namespace for core libraries such as game object and components
 */
namespace retronomicon::lib::core{
     
    class GameObject : public Entity {
        public:
            GameObject(const string& name);


            /**
             * @brief start function (used to initialize stuff)
             */
            void start() override;

            /**
             * @brief method to update the component
             * 
             * @param dt time interval since last update
             */
            void update(float dt) override;

            /**
             * @brief a method to render the component if any
             */
            void render(SDL_Renderer* renderer) override;


            const string& getName() const;
            void setName(const string& newName);

        private:
            string m_name;
    };
}
