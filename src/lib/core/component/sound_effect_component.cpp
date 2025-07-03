#include "retronomicon/lib/core/component/sound_effect_component.h"

namespace retronomicon::lib::core::component {

SoundEffectComponent::SoundEffectComponent()
    : volume_(1.0f), spatial_(false) {}

void SoundEffectComponent::queue_sound(const std::string& sound_id) {
    play_queue_.push_back(sound_id);
}

const std::vector<std::string>& SoundEffectComponent::get_play_queue() const {
    return play_queue_;
}

void SoundEffectComponent::clear_play_queue() {
    play_queue_.clear();
}

void SoundEffectComponent::set_volume(float volume) {
    volume_ = volume;
}

float SoundEffectComponent::get_volume() const {
    return volume_;
}

void SoundEffectComponent::set_spatial(bool spatial) {
    spatial_ = spatial;
}

bool SoundEffectComponent::is_spatial() const {
    return spatial_;
}

const char* SoundEffectComponent::get_type_name() const {
    return "SoundEffectComponent";
}

}
