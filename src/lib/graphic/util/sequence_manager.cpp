#include "retronomicon/lib/graphic/util/sequence_manager.h"

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::graphic::util{

    /**
     * @brief the constructor
     * 
     * @param frames the std::vector respresentation of the frames
     * @param frameCount the number of frame in this sequcne
     * @param name the name of of this animation
     * @param repeat set true if this animation is repeated
     */
    SequenceManager::SequenceManager(Sequence* defaultSequence){
        m_defaultSequence = defaultSequence;
        this->addSequence(defaultSequence);
        this->changeSequence(defaultSequence->getName());
    }

    /**
     *  @brief add a sequence to this state.
     * 
     * @param animationSequence the animation sequence that we'll be adding to the manager
     */
    bool SequenceManager::addSequence(Sequence* animationSequence){
        m_sequences[animationSequence->getName()] = animationSequence;
    }

    /**
     * @brief change the current sequence.
     * 
     * @param name the name of the animation sequence
     */
    void SequenceManager::changeSequence(const string& name){
        m_currentSequence = m_sequences[name];
    }
    
    /**
     * @brief get the current active sequence
     * 
     * @return the current sequence
     */
    Sequence* SequenceManager::getCurrentSequence() const{
        return m_currentSequence;
    }

    
    /**
     * @brief get the current active sequence name
     * 
     * @return the current sequence name
     */
    string SequenceManager::getCurrentStateName() const{
        return m_currentSequence->getName();
    }

    /**
     * @brief update function (might change in the future).
     * Potential update is to use time interval so we could do frame skipping
     * 
     * @return true if successfull, false if failed
     */
    bool SequenceManager::update(){
        m_currentSequence->update();
    }
}
