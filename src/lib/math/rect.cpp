#include "retronomicon/lib/math/rect.h"

#include <sstream>
/**
 * @brief The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::math{

    /***************************** To String *****************************/
    
    /**
     * @brief a method to help people debug this object
     * 
     * @return Brief summary of this object in string
     */
    std::string Rect::to_string() const{
        std::ostringstream oss;
        oss << "[Rectangle]\n";
        oss << "values:\n";
        oss << "- position = ("<< m_position.getX()<< "," <<  m_position.getY()   <<")\n";
        oss << "- anchor   = ("<< m_anchor.getX()<< "," <<  m_anchor.getY()   <<")\n";
        oss << "- width    = "<< m_width <<"\n";
        oss << "- height   = "<< m_height <<"\n";
        return oss.str();
    }

}