#pragma once

#include font.h
#include <string>

namespace retronomicon:lib:graphic{
	class Text {
		public:
		    Text(Font font, int fontSize);
		    // ~Font();

		    TTF_Font* getRawFont() const;
            bool isInitialized() const;
		private:
		    TTF_Font* m_font;
	};
}
