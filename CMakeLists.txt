# Note : There are significant changes version 3.15 onwards.
cmake_minimum_required(VERSION 3.15.0)
project(App VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)

add_executable (${PROJECT_NAME} apps/app.cpp)
target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE source_lib
)
set(EXECUTABLE_OUTPUT_PATH "bin")


if(UNIT_TESTS)
    message("Unit tests are enabled!")
    enable_testing()
    add_subdirectory(tests)
else()
    message("Unit tests are disabled!")
endif()

