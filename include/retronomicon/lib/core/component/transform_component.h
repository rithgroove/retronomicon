#pragma once

#include "component.h"
/**
 * @brief The namespace for core components
 */
namespace retronomicon::lib::core::component{
    /**
     * @brief The components that defines the position of an gameobject
     */
    class TransformComponent : public Component {
        public:
            /**
             * @brief empty constructor
             */
            TransformComponent();

            /**
             * @brief constuctor with parameters
             * 
             * @param x the x position
             * @param y the y position
             * @param rotation the rotation in degree (because human can calculate degree better) (default = 0.0f)
             * @param scaleX horizontal scaling  (default = 1.0f)
             * @param scaleY vertical scaling (default 1.0f)
             */
            TransformComponent(float x, float y, float rotation = 0.0f, float scaleX = 1.0f, float scaleY = 1.0f);

            /**
             * @brief a method to change x,y
             * 
             * @param x the x position
             * @param y the y position
             */
            void setPosition(float x, float y);

            /**
             * @brief a method to change rotation
             * 
             * @param angle the rotation angle in degree
             */
            void setRotation(float angle);

            /**
             * @brief a method to scale the components
             * 
             * @param scaleX horizontal scaling 
             * @param scaleY vertical scaling
             */
            void setScale(float scaleX, float scaleY);

            /**
             * @brief a method to get x
             * 
             * @return x value
             */
            float getX() const;
            
            /**
             * @brief a method to get y
             * 
             * @return y value
             */
            float getY() const;
            
            /**
             * @brief a method to get rotation angle
             * 
             * @return rotation angle
             */
            float getRotation() const;
            
            /**
             * @brief a method to get horizontal scaling
             * 
             * @return horizontal scaling
             */
            float getScaleX() const;

            /**
             * @brief a method to get vertical scaling
             * 
             * @return vertical scaling
             */
            float getScaleY() const;

        public:
            float x;
            float y;
            float rotation;
            float scaleX;
            float scaleY;
    };

} // namespace retronomicon