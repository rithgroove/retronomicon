echo downloading libraries
mkdir -p external
cd ./external

echo cloning SDL2

git clone -b release-2.24.2 https://github.com/libsdl-org/SDL.git SDL2
cd ./SDL2
cd ..

# if you get sdl2 init error: no display detected, try installing these:
#echo installing video depencencies for SDL2
#sudo apt-get install xorg-dev
#sudo apt-get install libsdl1.2debian:i386 

echo installing audio depencencies for SDL2
sudo apt-get install libasound2-dev libpulse-dev