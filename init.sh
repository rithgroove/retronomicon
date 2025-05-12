echo downloading libraries
mkdir -p external
cd ./external

echo cloning SDL2

git clone -b <branch> https://github.com/libsdl-org/SDL.git SDL2
cd ./SDL2
cd ..