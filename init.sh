#USE_PYTHON_SCRIPT = ${USE_PYTHON:-OFF}
#USE_LUA_SCRIPT = ${USE_LUA:-OFF}

echo downloading libraries
mkdir -p external
cd ./external

echo cloning SDL2

# echo cloning entt 
# git clone https://github.com/skypjack/entt.git entt
# cd ./entt
# cd ..

# echo cloning optional lib 
# git git clone https://github.com/TartanLlama/optional.git
# cd ./optional
# cd ..

if [ ${USE_LUA}  = "ON" ]; then 
	echo cloning Sol2
	git clone --recursive https://github.com/ThePhD/sol2
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

if [ ${USE_PYTHON} = "ON" ]; then
	sudo apt install python3-dev
fi


# if you get sdl2 init error: no display detected, try installing these:
#echo installing video depencencies for SDL2
sudo apt-get install xorg-dev
#sudo apt-get install libsdl1.2debian:i386 

echo installing audio depencencies for SDL2
sudo apt-get install libasound2-dev libpulse-dev
