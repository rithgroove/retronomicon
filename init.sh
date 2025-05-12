echo downloading libraries
mkdir -p external
cd ./external

echo cloning SDL2

git clone -b release-2.24.2 https://github.com/libsdl-org/SDL.git SDL2
cd ./SDL2
cd ..