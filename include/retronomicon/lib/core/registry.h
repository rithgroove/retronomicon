#pragma once
#include "entity.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <typeindex>

namespace retronomicon::lib::core {

class Registry {
public:
    Entity create_entity();

    template<typename T, typename... Args>
    T* add_component(Entity entity, Args&&... args);

    template<typename T>
    T* get_component(Entity entity);

    // (Extra methods: remove, has, etc.)

private:
    Entity::ID next_id_ = 1;

    std::unordered_map<std::type_index,
        std::unordered_map<Entity::ID, std::unique_ptr<Component>>> component_pools_;
};

}
