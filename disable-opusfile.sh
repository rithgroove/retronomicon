#!/bin/bash

# Path to your custom SDL2 build
SDL2_BUILD_DIR=${PWD}/../build/retronomicon_build/external/SDL2

# Export SDL2_CONFIG to help SDL2_mixer find your SDL2 build
export SDL2_CONFIG=${SDL2_BUILD_DIR}/sdl2-config

echo ${SDL2_CONFIG}

# Path to SDL2_mixer source directory (current)
cd external/SDL2_mixer

# Run SDL2_mixer's configure with --disable-opusfile
./configure --disable-opusfile

# Build SDL2_mixer
# make -j$(nproc)