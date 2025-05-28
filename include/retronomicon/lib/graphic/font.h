#pragma once

#include <SDL_ttf.h>
#include <string>

namespace retronomicon:lib:graphic{
	class Font {
		public:
		    Font(const std::string& filePath, int fontSize);
		    // ~Font();

		    TTF_Font* getRawFont() const;
            bool isInitialized() const;
		private:
		    TTF_Font* m_font;
	};
}
