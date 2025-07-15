#pragma once

#include <SDL_mixer.h>
#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/audio/music_component.h"
#include "retronomicon/lib/asset/music_asset.h"
#include "retronomicon/lib/asset/asset_manager.h"

namespace retronomicon::lib::audio {

    class MusicSystem : public retronomicon::lib::core::System {
    public:
        explicit MusicSystem(retronomicon::lib::asset::AssetManager* assetManager);

        void update(float dt, vector<retronomicon::lib::core::GameObject*>& objects)  override;

        // Optional: useful for editor or script control
        void playMusic(const MusicComponent& musicComp);
        void stopMusic();

    private:
        retronomicon::lib::asset::AssetManager* m_assetManager;
        std::string m_currentMusicPath = "";
    };

} // namespace retronomicon::lib::audio
