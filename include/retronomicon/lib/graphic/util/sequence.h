#pragma once
#include <string>
#include <SDL.h>
#include <math.h>
#include "frame.h"
#include <vector>

/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
using namespace retronomicon::lib::graphic::util;
using namespace std;
namespace retronomicon::lib::graphic::util{
	/**
	 * A class that represent a frame
	 */
    class Sequence {
	    public:
	    	Sequence(vector<Frame> frames, int frameCount,const string &name , bool repeat);
	    	 //constructor with 2 points (still considering wether we should use int or float or double)
	    	// ~Point(); // no need for destructor since all attributes are native
	    	// void set(int x, int y);//render function (might change in the future to include renderer)
	    	int getCurrentFrameIndex();
	    	Frame& getCurrentFrame();
	    	bool update();

	    private:
	    	vector<Frame> m_frames;
	    	string m_name;
	    	int m_frameCount;
	    	bool m_repeat;
	    	int m_currentFrame;
    };
} // namespace Retronomicon