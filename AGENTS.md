# Repository Guidelines

## Project Structure & Module Organization

`retronomicon` is the base C++17 engine library. Public APIs live in `include/retronomicon/`; implementations are organized by subsystem under `src/lib/` (`animation`, `asset`, `audio`, `core`, `engine`, `graphic`, `input`, `math`, `physics`, `scene`, `scripting`, and `ui`). Unit tests are in `tests/`. Third-party dependencies are vendored under `external/`; avoid editing them unless updating pinned libraries.

## Build, Test, and Development Commands

- `./init.sh`: prepares external SDL-related dependencies and optional Lua/Python support.
- `./build.sh`: configures `build/` with CMake and builds the engine.
- `cmake -S . -B build -DSDL2IMAGE_AVIF=OFF -DSDL2IMAGE_PNG=ON`: manual configure command matching the build script.
- `cmake --build build`: manual build.
- `./build/bin/engine_tests`: runs Catch2 tests after a successful build.

Set `USE_LUA=ON` or `USE_PYTHON=ON` before `./init.sh` only when those scripting integrations are needed.

## Coding Style & Naming Conventions

Use C++17 and match the existing subsystem style. Files use lowercase snake case, for example `sprite_component.cpp`. Types use PascalCase; functions and variables use lower camelCase. Keep public headers under `include/retronomicon/...` with matching implementation files in `src/lib/...`. Use 4-space indentation and keep namespace scopes explicit.

## Testing Guidelines

Tests use Catch2 in `tests/` and are named `test_*.cpp`. Add focused `TEST_CASE("behavior", "[subsystem]")` cases for engine math, asset, and runtime behavior changes. The `engine_tests` target is discovered through CMake and also runs after build.

## Commit & Pull Request Guidelines

Use short, imperative commit messages consistent with the workspace history, such as `fix math vector normalization` or `update audio loader`. PRs should summarize the affected subsystem, list verification commands, and note any dependency or asset changes.
