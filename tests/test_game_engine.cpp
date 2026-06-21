#include <catch2/catch_test_macros.hpp>

#include "retronomicon/audio/i_audio_player.h"
#include "retronomicon/engine/game_engine.h"
#include "retronomicon/graphics/renderer/i_renderer.h"
#include "retronomicon/input/input_map.h"
#include "retronomicon/input/raw_input.h"
#include "retronomicon/manager/render_manager.h"
#include "retronomicon/scene/scene.h"
#include "retronomicon/scene/scene_manager.h"

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

namespace {

class FakeRenderer : public retronomicon::graphics::renderer::IRenderer {
public:
    void init() override { ++initCount; }
    void clear() override { ++clearCount; }
    void show() override { ++showCount; }
    void shutdown() override { ++shutdownCount; }

    void render(std::shared_ptr<retronomicon::graphics::Texture>,
                const retronomicon::math::Vec2&,
                const retronomicon::math::Vec2&,
                float,
                float) override {
        ++textureRenderCount;
    }

    void renderQuad(std::shared_ptr<retronomicon::graphics::Texture>,
                    const retronomicon::math::Rect&,
                    const retronomicon::math::Rect&,
                    float,
                    float,
                    const retronomicon::graphics::Color&) override {
        ++quadRenderCount;
    }

    int getWidth() const override { return 800; }
    int getHeight() const override { return 600; }

    int initCount = 0;
    int clearCount = 0;
    int showCount = 0;
    int shutdownCount = 0;
    int textureRenderCount = 0;
    int quadRenderCount = 0;
};

class FakeRawInput : public retronomicon::input::RawInput {
public:
    void poll() override { ++pollCount; }
    void clear() override { events.clear(); pressed.clear(); }
    const std::vector<std::string>& getEvents() const override { return events; }
    bool isKeyPressed(retronomicon::input::Key key) const override {
        return pressed.count(key) > 0;
    }
    int getMouseX() const override { return mouseX; }
    int getMouseY() const override { return mouseY; }
    unsigned int getMouseButtons() const override { return mouseButtons; }

    int pollCount = 0;
    int mouseX = 0;
    int mouseY = 0;
    unsigned int mouseButtons = 0;
    std::vector<std::string> events;
    std::unordered_set<retronomicon::input::Key> pressed;
};

class CountingScene : public retronomicon::scene::Scene {
public:
    CountingScene() : Scene("counting") {}

    void start() override {
        ++startCount;
        Scene::start();
    }

    void update(float dt) override {
        ++updateCount;
        lastDelta = dt;
    }

    void shutdown() override {
        ++shutdownCount;
        Scene::shutdown();
    }

    int startCount = 0;
    int updateCount = 0;
    int shutdownCount = 0;
    float lastDelta = 0.0f;
};

std::shared_ptr<retronomicon::engine::GameEngine> makeEngine(
    std::shared_ptr<FakeRenderer> renderer,
    std::shared_ptr<retronomicon::scene::SceneManager> sceneManager) {
    auto renderManager = std::make_shared<retronomicon::manager::RenderManager>(renderer);
    return std::make_shared<retronomicon::engine::GameEngine>(renderManager, sceneManager);
}

} // namespace

TEST_CASE("GameEngine init validates injected core systems", "[engine]") {
    auto sceneManager = std::make_shared<retronomicon::scene::SceneManager>();
    auto engineWithoutRenderManager = std::make_shared<retronomicon::engine::GameEngine>(
        nullptr,
        sceneManager);

    REQUIRE_FALSE(engineWithoutRenderManager->init("test", 800, 600));

    auto renderManagerWithoutRenderer = std::make_shared<retronomicon::manager::RenderManager>(nullptr);
    auto engineWithoutRenderer = std::make_shared<retronomicon::engine::GameEngine>(
        renderManagerWithoutRenderer,
        sceneManager);

    REQUIRE_FALSE(engineWithoutRenderer->init("test", 800, 600));

    auto renderer = std::make_shared<FakeRenderer>();
    auto engine = makeEngine(renderer, sceneManager);

    REQUIRE(engine->init("test", 800, 600));
}

TEST_CASE("GameEngine tick maps input, updates scene, and presents frame", "[engine]") {
    using retronomicon::input::Key;

    auto renderer = std::make_shared<FakeRenderer>();
    auto sceneManager = std::make_shared<retronomicon::scene::SceneManager>();
    auto engine = makeEngine(renderer, sceneManager);

    auto rawInput = std::make_shared<FakeRawInput>();
    rawInput->pressed.insert(Key::Enter);
    rawInput->pressed.insert(Key::D);

    auto inputMap = std::make_shared<retronomicon::input::InputMap>();
    inputMap->bindAction(Key::Enter, "confirm");
    inputMap->bindAxis(Key::A, "move_x", -1.0f);
    inputMap->bindAxis(Key::D, "move_x", 1.0f);
    engine->setInputModule(inputMap, rawInput);

    auto scene = std::make_shared<CountingScene>();
    engine->registerScene("test", scene);
    engine->changeScene("test");

    REQUIRE(scene->startCount == 1);

    engine->tick(0.25f);

    REQUIRE(rawInput->pollCount == 1);
    REQUIRE(engine->getInputState()->isActionActive("confirm"));
    REQUIRE(engine->getInputState()->getAxis("move_x") == 1.0f);
    REQUIRE(scene->updateCount == 1);
    REQUIRE(scene->lastDelta == 0.25f);
    REQUIRE(renderer->clearCount == 1);
    REQUIRE(renderer->showCount == 1);
}
