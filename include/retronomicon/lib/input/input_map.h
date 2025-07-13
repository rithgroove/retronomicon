#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <SDL.h>
// #include "input_state.h"

/**
 * @brief This namespace is for handling input
 */
namespace retronomicon::lib::input {
    /**
     * @brief input mapping class
     */
    class InputMap {
        public:
            /***************************** Constructor *****************************/

            /**
             * @brief default constructor
             */
            InputMap();

            /***************************** Destructor *****************************/

            // ~InputMap();

            /***************************** Getter *****************************/
            /**
             * @brief method to get all action Bindings
             * 
             * @return unordered map of action bindings
             */
            const std::unordered_map<SDL_Scancode, std::string>& getActionBindings() const{ return m_actionBindings;}

            /**
             * @brief method to get all action Bindings
             * 
             * @return unordered map of axis bindings
             */
            const std::unordered_map<std::string, std::vector<std::pair<SDL_Scancode, float>>>& getAxisBindings() const{ return m_axisBindings;}


            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const InputMap& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            std::string to_string() const;

            /***************************** Main methods *****************************/

            /**
             * @brief a method to bind action to SDL key
             * 
             * @param key SDL_Scancode the SDL_Scancode key
             * @param actionName the action name (like jump/ attack/ etc)
             */
            void bindAction(SDL_Scancode key, const std::string& actionName);

            /**
             * @brief a method to bind axis to SDL key
             * 
             * @param key SDL_Scancode the SDL_Scancode key
             * @param axisName the axis name
             * @param weight how many value 
             */
            void bindAxis(SDL_Scancode key, const std::string& axisName, float weight);

        private:
            /***************************** Attribute *****************************/
            std::unordered_map<SDL_Scancode, std::string> m_actionBindings;
            std::unordered_map<std::string, std::vector<std::pair<SDL_Scancode, float>>> m_axisBindings;
    };

} // namespace retronomicon::lib::input
