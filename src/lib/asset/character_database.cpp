#include "retronomicon/lib/asset/character_database.h"
#include "retronomicon/lib/asset/text_asset.h"
#include <iostream>

namespace retronomicon::lib::asset {

    CharacterDatabase::CharacterDatabase(std::shared_ptr<AssetManager> assetManager) noexcept
        : m_assetManager(std::move(assetManager)) {}

    bool CharacterDatabase::loadDatabase(const std::string& path) noexcept {
        auto textAsset = m_assetManager->loadText(path, path);
        if (!textAsset) {
            std::cerr << "[CharacterDatabase] Failed to load database file: " << path << "\n";
            return false;
        }

        nlohmann::json json;
        try {
            json = nlohmann::json::parse(textAsset->getContent());
        } catch (const std::exception& e) {
            std::cerr << "[CharacterDatabase] JSON parse error: " << e.what() << "\n";
            return false;
        }

        if (!json.contains("characters") || !json["characters"].is_array()) {
            std::cerr << "[CharacterDatabase] Invalid database format (missing 'characters' array)\n";
            return false;
        }

        for (const auto& entry : json["characters"]) {
            std::string id = entry.value("id", "");
            std::string file = entry.value("file", "");
            if (id.empty() || file.empty()) {
                std::cerr << "[CharacterDatabase] Skipping entry with missing id or file\n";
                continue;
            }
            m_charactersFilepath[id] = file;
        }

        return true;
    }

    void CharacterDatabase::registerModuleLoader(std::shared_ptr<CharacterModuleLoader> loader) {
        m_loaders.push_back(std::move(loader));
    }


    [[nodiscard]] std::shared_ptr<core::Character> CharacterDatabase::getCharacter(const std::string& id) noexcept {
        auto it = m_characters.find(id);
        if (it != m_characters.end()) {
            return it->second;
        }

        // Do we have a filepath?
        auto fpIt = m_charactersFilepath.find(id);
        if (fpIt == m_charactersFilepath.end()) {
            std::cerr << "[CharacterDatabase] Character id not found in database: " << id << "\n";
            return nullptr;
        }

        const std::string& file = fpIt->second;
        auto charAsset = m_assetManager->loadText(file, file);
        if (!charAsset) {
            std::cerr << "[CharacterDatabase] Failed to load character file: " << file << "\n";
            return nullptr;
        }

        try {
            auto characterJson = nlohmann::json::parse(charAsset->getContent());
            auto character = std::make_shared<core::Character>(id,characterJson["name"],characterJson["displayName"],characterJson["description"]);

            // Let registered loaders fill the character
            // for (const auto& loader : m_loaders) {
            //     loader->load(characterJson, *character, m_assetManager);
            // }

            m_characters[id] = character;
            return character;
        } catch (const std::exception& e) {
            std::cerr << "[CharacterDatabase] Failed to parse character file (" << file << "): " << e.what() << "\n";
            return nullptr;
        }
    }

} // namespace retronomicon::lib::asset
