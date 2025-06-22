#pragma once

#include <unordered_map>
#include <queue>
#include "retronomicon/lib/graphic/animation/sequence.h"
#include "component.h"

using namespace retronomicon::lib::math;
using namespace retronomicon::lib::graphic::animation;

/**
 * @brief The namespace for graphic utilities
 */
namespace retronomicon::lib::core::component{
    /**
     * @brief A class that represent a frame in the animation sequence (the source image from sprite sheet)
     */
    class AnimationComponent : public Component {
        public:
            /**
             * @brief Constructor. initiate with default animation sequence
             * 
             * @param defaultSequence the default animation sequence
             */
            AnimationComponent(Sequence* defaultSequence);

            /**
             *  @brief add a sequence to this state.
             * 
             * @param animationSequence the animation sequence that we'll be adding to the manager
             */
            bool addSequence(Sequence* animationSequence);

            /**
             * @brief change the current sequence.
             * 
             * @param name the name of the animation sequence
             */
            void changeSequence(const string& name);

            /**
             * @brief get the current active sequence
             * 
             * @return the current sequence
             */
            Sequence* getCurrentSequence() const;


            /**
             * @brief get the current frome of the current active sequence
             * 
             * @return the current frame
             */
            Frame& getCurrentFrame() const;

            /**
             * @brief get the current active sequence name
             * 
             * @return the current sequence name
             */
            string getCurrentStateName() const;

            /**
             * @brief update function (might change in the future).
             * Potential update is to use time interval so we could do frame skipping
             * 
             * @return true if successfull, false if failed
             */
            void update(float dt) override;

            /**
             * @brief insert sequence to sequence Queue
             */
            void queueSequence(Sequence* Sequence);
        private:
            unordered_map<string, Sequence*> m_sequences;
            queue<Sequence*> m_sequenceQueue;
            Sequence* m_currentSequence;
            Sequence* m_defaultSequence;
    };
}