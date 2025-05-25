mkdir -p build-aarch64; 
cd build-aarch64
export LD_LIBRARY_PATH=/media/rithgroove/root/usr/lib/aarch64-linux-gnu
cmake -DCMAKE_TOOLCHAIN_FILE=../ToolChain/TC-arkos.cmake \
      -DMyGen_DIR=. ..
make
cp -R ../asset ./bin/