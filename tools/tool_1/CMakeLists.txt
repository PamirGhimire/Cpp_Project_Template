set(COMPONENT_NAME TOOL)
set(LIBRARY_NAME tool_lib)

add_library(${LIBRARY_NAME}
    STATIC
    tool.h
    tool.cpp
)

add_executable(${COMPONENT_NAME}  tool_main.cpp)
target_link_libraries(${COMPONENT_NAME} 
    PRIVATE
    ${LIBRARY_NAME}
    source_lib
)