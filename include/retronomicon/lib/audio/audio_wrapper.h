#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

namespace retronomicon::lib::audio {

    /**
     * @brief A wrapper class to encapsulate SDL_mixer init and cleanup.
     */
    class AudioWrapper {
    public:
        static bool init();
        static void shutdown();
    };

}