set(TEST_EXEC class1_tests)

add_executable(${TEST_EXEC} 
    class1_tests.cpp
)

target_include_directories(${TEST_EXEC}
    PRIVATE
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(
    ${TEST_EXEC} 
    PRIVATE gtest
    PRIVATE gtest_main
    PRIVATE source_lib
)

add_test(
    NAME 
    ${TEST_EXEC}
    COMMAND $<TARGET_FILE:${TEST_EXEC}>
)

#if test doesn't finish in 60 seconds, it's reported as timeout failure
set_tests_properties(${TEST_EXEC} PROPERTIES TIMEOUT 60) 

  