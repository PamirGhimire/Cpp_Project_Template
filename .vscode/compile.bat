rm -rf build
mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DUNIT_TESTS=ON -DBUILD_TOOLS=ON -DCMAKE_BUILD_TYPE=Debug
mingw32-make
ctest -VV 
cd ..