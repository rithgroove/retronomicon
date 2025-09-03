#pragma once

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "retronomicon/lib/core/character.h"

namespace retronomicon::lib::asset {
    using retronomicon::lib::core::Character;
    class CharacterModuleLoader {
        public:
            virtual ~CharacterModuleLoader() = default;

            /**
             * @brief Tag this loader is responsible for. e.g. "retronomicon-conversation"
             */
            // [[nodiscard]] virtual std::string tag() const noexcept = 0;

            /**
             * @brief Extend a character with data from a module-specific JSON section.
             * @param character The character object being loaded.
             * @param section The JSON section specific to this module.
             */
            virtual void load(std::shared_ptr<Character>& character, const nlohmann::json& json) = 0;
 
            void setAssetManager(std::shared_ptr<retronomicon::lib::asset::AssetManager> assetManager) noexcept {
                m_assetManager = std::move(assetManager);
            }

        protected:
            std::shared_ptr<AssetManager> m_assetManager;
    };

} // namespace retronomicon::lib::asset
