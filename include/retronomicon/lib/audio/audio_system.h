#pragma once

#include "retronomicon/lib/core/system.h"
#include "retronomicon/lib/audio/music_component.h"
#include "retronomicon/lib/audio/sound_effect_component.h"
#include "retronomicon/lib/audio/music_asset_player.h"
#include "retronomicon/lib/audio/sound_effect_asset_player.h"
#include "retronomicon/lib/audio/audio_wrapper.h"

#include <vector>

namespace retronomicon::lib::audio {

    /**
     * @brief System to manage playback of music and sound effects via components.
     */
    class AudioSystem : public retronomicon::lib::core::System {
    public:
        AudioSystem();
        ~AudioSystem();

        /**
         * @brief Overridden ECS update method that triggers audio playback.
         * 
         * @param dt delta time (unused)
         * @param objects list of game objects in the scene
         */
        void update(float dt, std::vector<retronomicon::lib::core::GameObject*>& objects) override;

        void clear();

    private:
        MusicAssetPlayer m_musicPlayer;
        SoundEffectAssetPlayer m_soundEffectPlayer;
    };

} // namespace retronomicon::lib::audio
