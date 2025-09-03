#pragma once

#include <memory>
#include <string>
#include <vector>
#include "retronomicon/lib/core/character.h"
#include "retronomicon/lib/asset/text_asset.h"
#include "retronomicon/lib/asset/character_module_loader.h"

namespace retronomicon::lib::asset {

    class CharacterLoader final {
    public:
        CharacterLoader() = delete;
        ~CharacterLoader() = delete;

        [[nodiscard]] static std::shared_ptr<retronomicon::lib::core::Character>
        loadFromJson(const std::string& jsonString);

        [[nodiscard]] static std::shared_ptr<retronomicon::lib::core::Character>
        loadFromTextAsset(const retronomicon::lib::asset::TextAsset& textAsset);

        /**
         * @brief Register a module loader. Call this during module init.
         */
        static void registerModuleLoader(std::shared_ptr<CharacterModuleLoader> loader);

    private:
        static std::vector<std::shared_ptr<CharacterModuleLoader>>& getModuleLoaders();
    };

} // namespace retronomicon::lib::asset
