#pragma once

#include <string>
#include "entity.h"

namespace retronomicon::lib::core {

/**
 * @brief Core representation of a character.
 *
 * Characters extend Entity so they can carry components.
 * At the core level, only general fields are stored:
 * - id
 * - name
 * - displayName
 * - description
 *
 * Specific modules (e.g., retronomicon-conversation, retronomicon-jrpg)
 * can extend the character by attaching their own components.
 */
class Character : public Entity {
    public:
        Character() noexcept = default;

        explicit Character(std::string id,
                           std::string name,
                           std::string displayName,
                           std::string description) noexcept;

        // --- Getters (inline) ---
        [[nodiscard]] inline const std::string& getId() const noexcept { return m_id; }
        [[nodiscard]] inline const std::string& getName() const noexcept { return m_name; }
        [[nodiscard]] inline const std::string& getDisplayName() const noexcept { return m_displayName; }
        [[nodiscard]] inline const std::string& getDescription() const noexcept { return m_description; }

        // --- Setters (inline) ---
        inline void setId(const std::string& id) noexcept { m_id = id; }
        inline void setName(const std::string& name) noexcept { m_name = name; }
        inline void setDisplayName(const std::string& displayName) noexcept { m_displayName = displayName; }
        inline void setDescription(const std::string& description) noexcept { m_description = description; }

    private:
        std::string m_id;
        std::string m_name;
        std::string m_displayName;
        std::string m_description;
    };

} // namespace retronomicon::lib::core
