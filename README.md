# GOT-PROJECT-3

# Installation

Build and install restclient-cpp using vcpkg dependency manager:

git clone https://github.com/Microsoft/vcpkg.git

cd vcpkg  
./bootstrap-vcpkg.sh  
./vcpkg integrate install  
./vcpkg install restclient-cpp  

After that, clone this repository and open the project with CLion.

Go to Settings > Build, Execution, Deployment > CMake

And finally in CMake options paste this: -DCMAKE_TOOLCHAIN_FILE=/home/user/vcpkg/scripts/buildsystems/vcpkg.cmake

Obviusly you need to change "/user/" for your username in ubuntu.
