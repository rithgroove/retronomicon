#pragma once

namespace retronomicon {
    namespace lib{
        namespace input{
			class InputDevice {
				public:
				    virtual ~InputDevice() = default;

				    virtual void update() = 0;
				    virtual bool isButtonPressed(int buttonCode) const = 0;
				    virtual bool isButtonReleased(int buttonCode) const = 0;
				    virtual bool isButtonHeld(int buttonCode) const = 0;
			};
		} // namespaceinput
	} // namespace lib
} // namespace retronomicon