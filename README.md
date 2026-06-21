# retronomicon

Backend-neutral core library for the Retronomicon workspace.

## Current Status

This repository is on the `remove_sdl` branch and is being shaped into the
engine core that graphics, audio, and gameplay modules plug into. The active
CMake target builds the modern core modules under `src/`:

- `entity`
- `component`
- `system`
- `manager`
- `math`
- `asset`
- `animation`
- `input`
- `engine`
- `scene`

The old `src/lib/*` tree still exists as migration/reference material, but most
of it is not part of the active `retronomicon` target.

## Backend Contracts

Concrete backend modules must implement these core interfaces:

- `retronomicon::graphics::renderer::IRenderer`
- `retronomicon::graphics::IWindow`
- `retronomicon::manager::TextureManager`
- `retronomicon::input::RawInput`
- `retronomicon::audio::IAudioPlayer`

Core code should not include SDL, OpenGL, Vulkan, DirectX, OpenAL, or platform
headers. Those belong in sibling backend repositories.

## GameEngine Contract

`GameEngine` coordinates injected systems. It does not create platform windows
or devices. Backend setup should happen outside core, then be injected through:

- `RenderManager`
- `SceneManager`
- `setInputModule(...)`
- `setAudioPlayer(...)`

`GameEngine::init(...)` currently validates that required injected systems are
available. `GameEngine::tick(dt)` advances one frame and exists so tests and
tools can verify loop behavior without entering `run()`.

## Build And Test

```sh
git submodule update --init --recursive
cmake -S . -B build
cmake --build build
```

The `engine_tests` target runs after build. Current coverage includes math and
basic engine coordination with fake renderer/input/scene test doubles.

## Continuation Checklist

1. Keep growing tests around backend contracts before large refactors.
2. Decide the fate of `src/lib/*`: migrate useful pieces or delete dead code.
3. Move any remaining SDL-specific active behavior out of core.
4. Add fake `TextureManager` tests for sprite/text rendering paths.
5. Add tests for scene reset/shutdown behavior.
6. Add a backend-neutral example scene in the workspace, then migrate
   conversation/card/platformer examples to use the same pattern.
7. Move concrete SDL_mixer and OpenAL audio implementations into
   `retronomicon-audio`.

## Notes For Future Codex Sessions

Start by running the core tests and reading `tests/test_game_engine.cpp`. That
file defines the current expected contract for injected backends. Avoid changing
backend APIs without updating both the fake test doubles and the SDL/OpenGL/
Vulkan backend implementations in the workspace.
