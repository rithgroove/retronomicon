#include "retronomicon/lib/core/character.h"

namespace retronomicon::lib::core {

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
