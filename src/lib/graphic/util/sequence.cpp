#include "retronomicon/lib/graphic/util/sequence.h"

/**
 * The namespace for basic libraries such as points, rectangle cirle, etc.
 */
namespace retronomicon::lib::graphic::util{

    /*************************************************************************************************
     * Constructor: with all 4 int 
     *************************************************************************************************/
    Sequence::Sequence(Frame* frames, int frameCount, string &name , bool repeat){
    	m_frames = frames;
    	m_frameCount = frameCount;
        m_name = name;
        m_repeat = repeat;
        m_currentFrame = 0;
    }

    int Sequence::getCurrentFrameIndex(){
    	return m_currentFrame;
    }

    Frame* Sequence::getCurrentFrame(){
    	return &m_frames[m_currentFrame];
    }

    bool Sequence::update(){
    	m_currentFrame++;
    	if (m_currentFrame >= m_frameCount){
    		if (m_repeat){
    			m_currentFrame = 0;
    		}else{
	    		m_currentFrame = m_frameCount-1;
    		}
    	}
    }
}
