#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <SDL.h>
#include "image_asset.h"
#include "font_asset.h"
#include "music_asset.h"
#include "sound_asset.h"
#include "text_asset.h"
#include "binary_asset.h"

namespace retronomicon::lib::asset {

class AssetManager {
public:
    AssetManager(SDL_Renderer* renderer);
    ~AssetManager();

    void clearAll();

    // Image Asset
    std::shared_ptr<ImageAsset> loadImage(const std::string& path, const std::string& name, bool forceReload = false);
    std::shared_ptr<ImageAsset> getImage(const std::string& name);
    bool removeImage(const std::string& name);

    // Font Asset
    std::shared_ptr<FontAsset> loadFont(const std::string& path, const std::string& name, int size, bool forceReload = false);
    std::shared_ptr<FontAsset> getFont(const std::string& name, int size);
    bool removeFont(const std::string& name, int size);

    // Music Asset
    std::shared_ptr<MusicAsset> loadMusic(const std::string& path, const std::string& name, bool forceReload = false);
    std::shared_ptr<MusicAsset> getMusic(const std::string& name);
    bool removeMusic(const std::string& name);

    // Sound Asset
    std::shared_ptr<SoundAsset> loadSound(const std::string& path, const std::string& name, bool forceReload = false);
    std::shared_ptr<SoundAsset> getSound(const std::string& name);
    bool removeSound(const std::string& name);

    // Text Asset
    std::shared_ptr<TextAsset> loadText(const std::string& path, const std::string& name, bool forceReload = false);
    std::shared_ptr<TextAsset> getText(const std::string& name);
    bool removeText(const std::string& name);

    // Binary Asset
    std::shared_ptr<BinaryAsset> loadBinary(const std::string& path, const std::string& name, bool forceReload = false);
    std::shared_ptr<BinaryAsset> getBinary(const std::string& name);
    bool removeBinary(const std::string& name);

private:
    SDL_Renderer* m_renderer;

    std::unordered_map<std::string, std::shared_ptr<ImageAsset>> m_images;
    std::unordered_map<std::string, std::shared_ptr<FontAsset>> m_fonts;
    std::unordered_map<std::string, std::shared_ptr<MusicAsset>> m_music;
    std::unordered_map<std::string, std::shared_ptr<SoundAsset>> m_sounds;
    std::unordered_map<std::string, std::shared_ptr<TextAsset>> m_texts;
    std::unordered_map<std::string, std::shared_ptr<BinaryAsset>> m_binaries;

    std::string fontKey(const std::string& name, int size) const;
    void logLoad(const std::string& type, const std::string& name, const std::string& path);
};

} // namespace retronomicon::lib::asset
