#pragma once

#include <vector>
#include <string>
#include "retronomicon/lib/core/component.h"

using namespace retronomicon::lib::core;

namespace retronomicon::lib::core::component {

    class SoundEffectComponent : public Component {
        public:
            SoundEffectComponent();

            void queue_sound(const std::string& sound_id);
            const std::vector<std::string>& get_play_queue() const;
            void clear_play_queue();

            void set_volume(float volume);
            float get_volume() const;

            void set_spatial(bool spatial);
            bool is_spatial() const;

            // const char* get_type_name() const override;

        private:
            std::vector<std::string> play_queue_;
            float volume_;
            bool spatial_;
    };

}
