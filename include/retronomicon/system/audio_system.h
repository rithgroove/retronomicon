#pragma once

#include <memory>
#include "retronomicon/core/ecs/system.h"
#include "retronomicon/core/ecs/entity.h"
#include "retronomicon/audio/i_audio_player.h"

namespace retronomicon::audio {

    using retronomicon::core::ecs::Entity;

    /**
     * @brief System responsible for handling playback of MusicComponent and SoundEffectComponent.
     */
    class AudioSystem : public retronomicon::core::ecs::System {
    public:
        /**
         * @brief Construct the AudioSystem with a given audio player backend.
         */
        explicit AudioSystem(std::shared_ptr<IAudioPlayer> audioPlayer);

        /**
         * @brief Debug helper.
         */
        virtual std::string to_string() const;

        /**
         * @brief Traverse entities and update all audio-related components.
         */
        void update(float dt, std::weak_ptr<Entity> entity) override;

    private:
        std::shared_ptr<IAudioPlayer> m_audioPlayer;
    };

} // namespace retronomicon::audio
