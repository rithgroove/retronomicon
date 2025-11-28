#include "retronomicon/core/game/character.h"

namespace retronomicon::core::game {

  // --- Constructor ---
  Character::Character(std::string id,
                       std::string name,
                       std::string displayName,
                       std::string description) noexcept
      : m_id(std::move(id)),
        m_name(std::move(name)),
        m_displayName(std::move(displayName)),
        m_description(std::move(description)) {}

} // namespace retronomicon::lib::core
