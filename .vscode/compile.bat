@REM rm -rf build
@REM mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DUNIT_TESTS=ON -DBUILD_TOOLS=ON -DCMAKE_BUILD_TYPE=Debug
mingw32-make -j12
@REM "%CD%"\bin\App.exe
ctest -VV 
cd ..