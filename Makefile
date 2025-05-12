retronomicon	: ./src/main.cpp
	g++ ./src/main.cpp -o ./build/retronomicon `sdl2-config --cflags --libs`