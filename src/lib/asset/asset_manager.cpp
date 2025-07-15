#include "retronomicon/lib/asset/asset_manager.h"
#include <iostream>
#include <fstream>

namespace retronomicon::lib::asset {

AssetManager::AssetManager(SDL_Renderer* renderer) : m_renderer(renderer) {}

AssetManager::~AssetManager() {
    clearAll();
}

void AssetManager::clearAll() {
    m_images.clear();
    m_fonts.clear();
    m_music.clear();
    m_sounds.clear();
    m_texts.clear();
    m_binaries.clear();
}

void AssetManager::logLoad(const std::string& type, const std::string& name, const std::string& path) {
    std::cout << "[AssetManager] Loaded " << type << " [" << name << "] from " << path << std::endl;
}

std::shared_ptr<ImageAsset> AssetManager::loadImage(const std::string& path, const std::string& name, bool forceReload) {
    auto it = m_images.find(name);
    if (it != m_images.end() && !forceReload) {
        return it->second;
    }
    auto image = std::make_shared<ImageAsset>(path, name, m_renderer);
    m_images[name] = image;
    logLoad("Image", name, path);
    return image;
}

std::shared_ptr<ImageAsset> AssetManager::getImage(const std::string& name) {
    auto it = m_images.find(name);
    if (it != m_images.end()) return it->second;
    throw std::runtime_error("Image not found: " + name);
}

bool AssetManager::removeImage(const std::string& name) {
    return m_images.erase(name) > 0;
}

std::shared_ptr<FontAsset> AssetManager::loadFont(const std::string& path, const std::string& name, int size, bool forceReload) {
    std::string key = fontKey(name, size);
    auto it = m_fonts.find(key);
    if (it != m_fonts.end() && !forceReload) {
        return it->second;
    }
    auto font = std::make_shared<FontAsset>(path, name, size, m_renderer);
    m_fonts[key] = font;
    logLoad("Font", key, path);
    return font;
}

std::shared_ptr<FontAsset> AssetManager::getFont(const std::string& name, int size) {
    std::string key = fontKey(name, size);
    auto it = m_fonts.find(key);
    if (it != m_fonts.end()) return it->second;
    throw std::runtime_error("Font not found: " + key);
}

bool AssetManager::removeFont(const std::string& name, int size) {
    return m_fonts.erase(fontKey(name, size)) > 0;
}

std::shared_ptr<MusicAsset> AssetManager::loadMusic(const std::string& path, const std::string& name, bool forceReload) {
    auto it = m_music.find(name);
    if (it != m_music.end() && !forceReload) return it->second;
    auto music = std::make_shared<MusicAsset>(path, name);
    m_music[name] = music;
    logLoad("Music", name, path);
    return music;
}

std::shared_ptr<MusicAsset> AssetManager::getMusic(const std::string& name) {
    auto it = m_music.find(name);
    if (it != m_music.end()) return it->second;
    throw std::runtime_error("Music not found: " + name);
}

bool AssetManager::removeMusic(const std::string& name) {
    return m_music.erase(name) > 0;
}

std::shared_ptr<SoundEffectAsset> AssetManager::loadSound(const std::string& path, const std::string& name, bool forceReload) {
    auto it = m_sounds.find(name);
    if (it != m_sounds.end() && !forceReload) return it->second;
    auto sound = std::make_shared<SoundEffectAsset>(path, name);
    m_sounds[name] = sound;
    logLoad("Sound", name, path);
    return sound;
}

std::shared_ptr<SoundEffectAsset> AssetManager::getSound(const std::string& name) {
    auto it = m_sounds.find(name);
    if (it != m_sounds.end()) return it->second;
    throw std::runtime_error("Sound not found: " + name);
}

bool AssetManager::removeSound(const std::string& name) {
    return m_sounds.erase(name) > 0;
}

std::shared_ptr<TextAsset> AssetManager::loadText(const std::string& path, const std::string& name, bool forceReload) {
    auto it = m_texts.find(name);
    if (it != m_texts.end() && !forceReload) return it->second;
    auto text = std::make_shared<TextAsset>(path, name);
    m_texts[name] = text;
    logLoad("Text", name, path);
    return text;
}

std::shared_ptr<TextAsset> AssetManager::getText(const std::string& name) {
    auto it = m_texts.find(name);
    if (it != m_texts.end()) return it->second;
    throw std::runtime_error("Text not found: " + name);
}

bool AssetManager::removeText(const std::string& name) {
    return m_texts.erase(name) > 0;
}

std::shared_ptr<BinaryAsset> AssetManager::loadBinary(const std::string& path, const std::string& name, bool forceReload) {
    auto it = m_binaries.find(name);
    if (it != m_binaries.end() && !forceReload) return it->second;
    auto binary = std::make_shared<BinaryAsset>(path, name);
    m_binaries[name] = binary;
    logLoad("Binary", name, path);
    return binary;
}

std::shared_ptr<BinaryAsset> AssetManager::getBinary(const std::string& name) {
    auto it = m_binaries.find(name);
    if (it != m_binaries.end()) return it->second;
    throw std::runtime_error("Binary not found: " + name);
}

bool AssetManager::removeBinary(const std::string& name) {
    return m_binaries.erase(name) > 0;
}

std::string AssetManager::fontKey(const std::string& name, int size) const {
    return name + "-" + std::to_string(size);
}

} // namespace retronomicon::lib::asset
