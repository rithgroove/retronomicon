#pragma once

#include <string>
#include <vector>
#include "frame.h"

using namespace retronomicon::lib::graphic::util;
using namespace std;

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::util{
	/**
	 * @brief A class that represent an animation sequence.
	 * each frame will be represented by an instance of Frame class.
	 */
    class Sequence {
	    public:
	    	/**
	    	 * @brief the constructor
	    	 * 
	    	 * @param frames the std::vector respresentation of the frames
	    	 * @param frameCount the number of frame in this sequcne
	    	 * @param name the name of of this animation
	    	 * @param repeat set true if this animation is repeated
	    	 */
	    	Sequence(vector<Frame> frames, int frameCount,const string &name , bool repeat);

	    	// ~Point(); // no need for destructor since all attributes are native

	    	/**
	    	 * @brief get the current frame index
	    	 * 
	    	 * @return the current frame number
	    	 */
	    	int getCurrentFrameIndex();

	    	/**
	    	 * @brief get the current frame
	    	 * 
	    	 * @return the current frame
	    	 */
	    	Frame& getCurrentFrame();

	    	/**
	    	 * @brief get the name of this sequence
	    	 * 
	    	 * @return name of the sequence
	    	 */
	    	string getName() const;

	    	/**
	    	 * @brief update the frame to the next one
	    	 * 
	    	 * @return true if successful, false if failed.
	    	 */
	    	bool update();

	    	/**
	    	 * @brief a method to check if the animation is finished?
	    	 * 
	    	 * @return true if m_repeat is false, and is currently on the last frame
	    	 */
	    	bool isFinished();

	    private:
	    	vector<Frame> m_frames;
	    	string m_name;
	    	int m_frameCount;
	    	bool m_repeat;
	    	int m_currentFrame;
    };
} // namespace Retronomicon