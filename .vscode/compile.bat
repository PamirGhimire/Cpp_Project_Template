rm -rf build
mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DUNIT_TESTS=OFF -DCMAKE_BUILD_TYPE=Debug
mingw32-make -j12
"%CD%"\bin\App.exe
@REM ctest -VV 
cd ..