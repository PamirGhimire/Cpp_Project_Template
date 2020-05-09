# Note : There are significant changes version 3.15 onwards.
cmake_minimum_required(VERSION 3.15.0)
project(SAMPLE_APP VERSION 1.0.0 LANGUAGES CXX)

if(UNIX)
    message(STATUS "COMPILING FOR UNIX : ${UNIX}")
    add_definitions(-DHAVE_SIGNAL_H) #for cmocka testing lib
endif(UNIX)

add_subdirectory(library1)
add_subdirectory(library2)
add_subdirectory(src)


add_executable (${PROJECT_NAME} apps/app.cpp)
target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE source_lib
)
set(EXECUTABLE_OUTPUT_PATH "bin")

if(BUILD_TOOLS)
    add_subdirectory(tools)
endif()

if(UNIT_TESTS)
    message("Unit tests are enabled!")
    enable_testing()
    add_subdirectory(tests)
else()
    message("Unit tests are disabled!")
endif()

