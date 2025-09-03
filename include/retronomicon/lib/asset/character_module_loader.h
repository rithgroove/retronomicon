#pragma once

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "retronomicon/lib/core/character.h"

namespace retronomicon::lib::asset {

    class CharacterModuleLoader {
    public:
        virtual ~CharacterModuleLoader() = default;

        /**
         * @brief Tag this loader is responsible for. e.g. "retronomicon-conversation"
         */
        [[nodiscard]] virtual std::string tag() const noexcept = 0;

        /**
         * @brief Extend a character with data from a module-specific JSON section.
         * @param character The character object being loaded.
         * @param section The JSON section specific to this module.
         */
        virtual void load(std::shared_ptr<retronomicon::lib::core::Character>& character,
                          const nlohmann::json& section) const = 0;
    };

} // namespace retronomicon::lib::asset
