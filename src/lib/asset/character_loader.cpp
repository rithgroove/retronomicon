#include "retronomicon/lib/asset/character_loader.h"
#include <nlohmann/json.hpp>
#include <stdexcept>

using json = nlohmann::json;

namespace retronomicon::lib::asset {

    std::vector<std::shared_ptr<CharacterModuleLoader>>& CharacterLoader::getModuleLoaders() {
        static std::vector<std::shared_ptr<CharacterModuleLoader>> loaders;
        return loaders;
    }

    void CharacterLoader::registerModuleLoader(std::shared_ptr<CharacterModuleLoader> loader) {
        getModuleLoaders().push_back(std::move(loader));
    }

    [[nodiscard]] std::shared_ptr<retronomicon::lib::core::Character>
    CharacterLoader::loadFromJson(const std::string& jsonString) {
        auto character = std::make_shared<retronomicon::lib::core::Character>();

        try {
            auto j = json::parse(jsonString);

            if (j.contains("id")) {
                character->setId(j["id"].get<std::string>());
            }
            if (j.contains("name")) {
                character->setName(j["name"].get<std::string>());
            }
            if (j.contains("description")) {
                character->setDescription(j["description"].get<std::string>());
            }

            // Let all registered module loaders try to extend
            for (auto& loader : getModuleLoaders()) {
                auto tag = loader->tag();
                if (j.contains(tag)) {
                    loader->load(character, j[tag]);
                }
            }

        } catch (const std::exception& e) {
            throw std::runtime_error(std::string("CharacterLoader::loadFromJson failed: ") + e.what());
        }

        return character;
    }

    [[nodiscard]] std::shared_ptr<retronomicon::lib::core::Character>
    CharacterLoader::loadFromTextAsset(const retronomicon::lib::asset::TextAsset& textAsset) {
        return loadFromJson(textAsset.getContent());
    }

} // namespace retronomicon::lib::asset
