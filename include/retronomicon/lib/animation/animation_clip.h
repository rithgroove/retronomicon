#pragma once

#include <string>
#include <vector>
#include "animation_frame.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::animation{
	/**
	 * @brief A class that represent an animation AnimationClip.
	 * each frame will be represented by an instance of Frame class.
	 */
    class AnimationClip {
	    public:
	    	/**
	    	 * @brief the constructor
	    	 * 
	    	 * @param frames the std::vector respresentation of the frames
	    	 * @param name the name of of this animation
	    	 * @param repeat set true if this animation is repeated
	    	 */
    		AnimationClip(const std::vector<AnimationFrame>& frames, std::string name,bool repeat);

	    	// ~Point(); // no need for destructor since all attributes are native

	    	/**
	    	 * @brief get the current frame index
	    	 * 
	    	 * @return the current frame number
	    	 */
		    size_t getCurrentFrameIndex() const;

	    	/**
	    	 * @brief get the current frame
	    	 * 
	    	 * @return the current frame
	    	 */
    		const AnimationFrame& getCurrentFrame() const;


	    	/**
	    	 * @brief update the frame to the next one
	    	 * 
	    	 * @return left over delta time
	    	 */
            float update(float dt);

	    	/**
	    	 * @brief a method to check if the animation is finished?
	    	 * 
	    	 * @return true if m_repeat is false, and is currently on the last frame
	    	 */    
            bool isFinished() const;

			/**
	    	 * @brief geter of the name of this AnimationClip
	    	 * 
	    	 * @return name of the AnimationClip
	    	 */    
    		const std::string& name() const { return m_name; }


	    private:
	    	std::vector<AnimationFrame> m_frames;
	    	std::string m_name;
	    	bool m_repeat		= false;
	    	int m_currentFrame	= 0;
    };
} // namespace Retronomicon