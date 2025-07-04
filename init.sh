USE_PYTHON_SCRIPT = true
USE_LUA_SCRIPT = true


echo downloading libraries
mkdir -p external
cd ./external

echo cloning SDL2

git clone -b release-2.24.2 https://github.com/libsdl-org/SDL.git SDL2
cd ./SDL2
cd ..

echo cloning SDL2_ttf
git clone -b release-2.24.x git@github.com:libsdl-org/SDL_ttf.git SDL2_ttf
cd ./SDL2_ttf
cd ..


echo cloning SDL2_image
git clone -b release-2.8.x git@github.com:libsdl-org/SDL_image.git SDL2_image
cd ./SDL2_image
cd ..

# echo cloning entt 
# git clone https://github.com/skypjack/entt.git entt
# cd ./entt
# cd ..

# echo cloning optional lib 
# git git clone https://github.com/TartanLlama/optional.git
# cd ./optional
# cd ..

if [$USE_LUA_SCRIPT == true];
then 
	echo cloning Sol2
	git git clone --recursive https://github.com/ThePhD/sol2
	cd ./sol2
	cd ..

	curl -R -O https://www.lua.org/ftp/lua-5.3.6.tar.gz
	tar zxf lua-5.3.6.tar.gz
	cd lua-5.3.6
	cd ..
fi
#echo cloning nlohmann/json
#git clone git@github.com:nlohmann/json.git nlohmann/json
#cd ./nlohmann/json
#cd ../..

if [$USE_PYTHON_SCRIPT = true];
then
	sudo apt install python3-dev
fi


# if you get sdl2 init error: no display detected, try installing these:
#echo installing video depencencies for SDL2
sudo apt-get install xorg-dev
#sudo apt-get install libsdl1.2debian:i386 

echo installing audio depencencies for SDL2
sudo apt-get install libasound2-dev libpulse-dev
