add_library(
  library1
  library1Class.h
  library1Class.cpp
)

target_include_directories(
    library1
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# target_link_libraries(
#   # external dependencies for library1 here
# )

set_target_properties(library1 PROPERTIES LINKER_LANGUAGE CXX)