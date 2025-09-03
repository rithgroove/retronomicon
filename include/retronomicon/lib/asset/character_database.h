#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include "retronomicon/lib/core/character.h"
#include "retronomicon/lib/asset/asset_manager.h"
#include "retronomicon/lib/asset/character_module_loader.h"

namespace retronomicon::lib::asset {

class CharacterDatabase {
    public:
        explicit CharacterDatabase(std::shared_ptr<AssetManager> assetManager) noexcept;

        [[nodiscard]] bool loadDatabase(const std::string& path) noexcept;

        [[nodiscard]] std::shared_ptr<core::Character> getCharacter(const std::string& id) noexcept;
        /**
         * @brief Register a module loader. Call this during module init.
         */
        void registerModuleLoader(std::shared_ptr<CharacterModuleLoader> loader);
        void init();
    private:
        std::shared_ptr<AssetManager> m_assetManager;
        std::vector<std::shared_ptr<CharacterModuleLoader>> m_loaders;
        std::unordered_map<std::string,std::string> m_charactersFilepath;
        std::unordered_map<std::string, std::shared_ptr<core::Character>> m_characters;
    };

} // namespace retronomicon::lib::asset
