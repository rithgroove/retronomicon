# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)


# which compilers to use for C and C++
set(CMAKE_C_COMPILER   aarch64-linux-gnu-gcc-7)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++-7)


#set(CT_LIBC_VERSION 2.30)
#set(CT_LIBC_GLIBC_V_2_30 y)
#CT_LIBC_GLIBC_MIN_KERNEL_VERSION="2.6.9"
#CT_LIBC_GLIBC_MIN_KERNEL="2.6.9

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /media/rithgroove/root/usr/lib/aarch64-linux-gnu)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
