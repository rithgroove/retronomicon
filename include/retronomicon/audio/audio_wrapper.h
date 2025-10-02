#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
/**
 * @brief The namespace for audio 
 */
namespace retronomicon::lib::audio {

    /**
     * @brief A wrapper class to encapsulate SDL_mixer init and cleanup.
     */
    class AudioWrapper {
        public:

            /***************************** Main Methods *****************************/

            /**
             * @brief A wrapper class to encapsulate SDL_mixer init 
             */
            static bool init();

            /**
             * @brief A wrapper class to encapsulate SDL_mixer cleanup.
             */
            static void shutdown();
    };

}