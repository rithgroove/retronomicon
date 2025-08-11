#pragma once

#include <string>
#include <vector>
#include "animation_frame.h"

/**
 * @brief The namespace for animation utilities
 */
namespace retronomicon::lib::animation{
	/**
	 * @brief A class that represent an animation AnimationClip.
	 * each frame will be represented by an instance of Frame class.
	 */
    class AnimationClip {
	    public:
		    /***************************** Constructor *****************************/

	    	/**
	    	 * @brief the constructor
	    	 * 
	    	 * @param frames the std::vector respresentation of the frames
	    	 * @param name the name of of this animation
	    	 * @param repeat set true if this animation is repeated
	    	 */
    		AnimationClip(const std::vector<AnimationFrame>& frames, const std::string& name,bool repeat);

		    /***************************** Destructor *****************************/

	    	// ~AnimationClip(); // using default destructor

	    	/***************************** Setter *****************************/

	    	/**
	    	 * @brief set current frame number
	    	 * 
	    	 * @param frame the new frame index
	    	 */
	        void setCurrentFrame(int frame) { m_currentFrame = frame; }

	    	/**
	    	 * @brief set this clip to repeat or not
	    	 * 
	    	 * @param repeat boolean true = repeat, false = one time
	    	 */
	        void setRepeat(bool repeat) { m_repeat = repeat;} 

	    	/***************************** Getter *****************************/

			/**
	    	 * @brief getter of the name of this AnimationClip
	    	 * 
	    	 * @return name of the AnimationClip
	    	 */    
	        const std::string& getName() const { return m_name; }

			/**
	    	 * @brief getter of the current frame index
	    	 * 
	    	 * @return the current frame index
	    	 */    
	        size_t getCurrentFrameIndex() const { return static_cast<size_t>(m_currentFrame); }

			/**
	    	 * @brief getter of the current frame
	    	 * 
	    	 * @return the current frame in AnimationFrame class
	    	 */    
	        const AnimationFrame& getCurrentFrame() const { return m_frames[m_currentFrame]; }

			/**
	    	 * @brief get the number of frame in this clip
	    	 * 
	    	 * @return the number of frame
	    	 */    
	        int getFrameCount() const {return static_cast<int>(m_frames.size());}

	    	/***************************** Utility *****************************/

	        /**
	    	 * @brief utility to check if it's repeating or not
	    	 * 
	    	 * @return the current frame in AnimationFrame class
	    	 */    
	        bool isRepeating() const { return m_repeat; }

	    	/**
	    	 * @brief a method to check if the animation is finished?
	    	 * 
	    	 * @return true if m_repeat is false, and is currently on the last frame
	    	 */    
            bool isFinished() const;

	    	/***************************** Operator Overload *****************************/

            /**
             * @brief overloading operator << to call to_string()
             */
            friend std::ostream& operator<<(std::ostream& os, const AnimationClip& obj) {
                return os << obj.to_string();
            }

	    	/***************************** To String *****************************/

	    	/**
	    	 * @brief a method to help people debug this object
	    	 * 
	    	 * @return Brief summary of this object in string
	    	 */
	    	std::string to_string() const;

		    /***************************** Main Methods *****************************/

	    	/**
	    	 * @brief update the frame to the next one
	    	 * 
	    	 * @return left over delta time
	    	 */
            float update(float dt);

	    private:
            /***************************** Attribute *****************************/
	    	std::vector<AnimationFrame> m_frames;
	    	std::string m_name;
	    	bool m_repeat		= false;
	    	int m_currentFrame	= 0;
    };
} // namespace Retronomicon