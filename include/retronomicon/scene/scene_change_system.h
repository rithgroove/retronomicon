#pragma once
#include <retronomicon/core/ecs/system.h>
#include <retronomicon/core/ecs/entity.h>
#include <retronomicon/core/ecs/scene_change_component.h>

namespace retronomicon::scene {

class Engine; // forward declaration

class SceneChangeSystem : public core::ecs::System {
public:
    explicit SceneChangeSystem(Engine* engine)
        : m_engine(engine) {}

    void update(float dt, std::weak_ptr<core::ecs::Entity> entity) override;

private:
    Engine* m_engine = nullptr; // non-owning pointer to the engine controlling scenes
};

} // namespace retronomicon::scene
