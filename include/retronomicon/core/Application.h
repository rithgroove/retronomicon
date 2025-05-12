#pragma once

namespace MyGame 
{    
    class Application {
        public:
            Application(); //constructor
            ~Application(); //destructor
            void run(); //main run function

        private:
            bool isRunning;
            void init();
            void update();
            void render();
            void shutdown();
    };
} // namespace MyGame