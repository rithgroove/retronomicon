#include "retronomicon/lib/engine/exit_game_component.h"

namespace retronomicon::lib::engine {

    ExitGameComponent::ExitGameComponent()
        : m_activated(false) {}

    ExitGameComponent::~ExitGameComponent() = default;

    bool ExitGameComponent::isActivated() const {
        return m_activated;
    }

    void ExitGameComponent::activate() {
        m_activated = true;
    }

    void ExitGameComponent::reset() {
        m_activated = false;
    }

} // namespace retronomicon::lib::core