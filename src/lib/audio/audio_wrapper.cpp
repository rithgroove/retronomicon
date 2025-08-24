#include "retronomicon/lib/audio/audio_wrapper.h"

/**
 * @brief The namespace for audio 
 */
namespace retronomicon::lib::audio {

    /***************************** Main Methods *****************************/
    /**
     * @brief A wrapper class to encapsulate SDL_mixer init 
     */
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

    /**
     * @brief A wrapper class to encapsulate SDL_mixer cleanup.
     */
    void AudioWrapper::shutdown() {
        Mix_CloseAudio();
        Mix_Quit();
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
    }

}