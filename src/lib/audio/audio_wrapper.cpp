#include "retronomicon/lib/audio/audio_wrapper.h"

namespace retronomicon::lib::audio {

    bool AudioWrapper::init() {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            std::cerr << "SDL audio init failed: " << SDL_GetError() << std::endl;
            return false;
        }

        int flags = MIX_INIT_OGG; // Only OGG if all others disabled
        if ((Mix_Init(flags) & flags) != flags) {
            std::cerr << "SDL_mixer init failed: " << Mix_GetError() << std::endl;
            return false;
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cerr << "SDL_mixer open failed: " << Mix_GetError() << std::endl;
            return false;
        }

        return true;
    }

    void AudioWrapper::shutdown() {
        Mix_CloseAudio();
        Mix_Quit();
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
    }

}