#pragma once

#include <string>

/**
 * @brief The namespace for assets and loaders
 */
namespace retronomicon::lib::asset {
    /**
     * @brief abstract class that will be extended by many asset types
     */ 
    class Asset {
        public:

            /***************************** Destructor *****************************/

            /**
             * @brief default destructor
             */ 
            virtual ~Asset() = default;

            /***************************** Getter *****************************/

            /**
             * @brief getter for path
             * 
             * @return path to the file
             */
            std::string getPath() noexcept {return m_path;}
            
            /**
             * @brief getter for filename
             * 
             * @return name of the file
             */
            std::string getName() noexcept {return m_name;}

            /***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const Asset& obj) {
                return os << obj.to_string();
            }

            /***************************** To String *****************************/

            /**
             * @brief a method to help people debug this object
             * 
             * @return Brief summary of this object in string
             */
            virtual std::string to_string() const = 0;

        protected:
            /***************************** attributes *****************************/
            std::string m_path;
            std::string m_name;
    };
}