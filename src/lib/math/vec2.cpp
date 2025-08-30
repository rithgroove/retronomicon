#include "retronomicon/lib/math/vec2.h"
#include <sstream>
/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math {

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string Vec2::to_string() const{
        std::ostringstream oss;
        oss << "[Vector]\n";
        oss << "values:\n";
        oss << "- x      = "<< x <<"\n";
        oss << "- y      = "<< y <<"\n";
        oss << "- length = "<< length() <<"\n";
        return oss.str();
    }

}