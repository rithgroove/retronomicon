#pragma once

#include "component.h"
#include "retronomicon/math/vec2.h"
/**
 * @brief The namespace for core components
 */
namespace retronomicon::component{
    using retronomicon::math::Vec2;
    /**
     * @brief Defines position, rotation, and scale of an entity.
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
             * @brief a method to scale the anchor position (usefull for rotation)
             * 
             * @param anchorX the x position of the anchor (between 0.0 -1.0) 
             * @param anchorT the y position of the anchor (between 0.0 -1.0) 
             */
            void setAnchor(float anchorX, float anchorY);

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
            
            /**
             * @brief a method to get horizontal scaling
             * 
             * @return horizontal scaling
             */
            float getAnchorX() const;

            /**
             * @brief a method to get vertical scaling
             * 
             * @return vertical scaling
             */
            float getAnchorY() const;

            /**
             * @brief a method to raw position of the image. (x,y)
             * 
             * @return Vec2 of the position
             */
            Vec2 getPosition() const;

            /**
             * @brief a method to get the render position of the image (might need to add viewport later)
             * this methods loops their parent's transforms
             * 
             * @return Vec2 of the render position
             */
            Vec2 getRenderPosition() const ;

        private:
            float m_x = 0.0f;
            float m_y = 0.0f;
            float m_rotation = 0.0f;
            float m_scaleX =0.0f;
            float m_scaleY = 0.0f;
            float m_anchorX = 0.5f;
            float m_anchorY = 0.5f;
    };

} // namespace retronomicon