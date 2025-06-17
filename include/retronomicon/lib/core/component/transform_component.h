#pragma once

#include "component.h"

namespace retronomicon::lib::core::component{

    class TransformComponent : public Component {
        public:
            TransformComponent();
            TransformComponent(float x, float y, float rotation = 0.0f, float scaleX = 1.0f, float scaleY = 1.0f);

            void setPosition(float x, float y);
            void setRotation(float angle);
            void setScale(float scaleX, float scaleY);

            float getX() const;
            float getY() const;
            float getRotation() const;
            float getScaleX() const;
            float getScaleY() const;

        public:
            float x;
            float y;
            float rotation;
            float scaleX;
            float scaleY;
    };

} // namespace retronomicon