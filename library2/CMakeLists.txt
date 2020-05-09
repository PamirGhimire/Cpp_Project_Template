add_library(
  library2
  library2Class.h
  library2Class.cpp
)

target_include_directories(
    library2
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# target_link_libraries(
#   # external dependencies for library1 here
# )

set_target_properties(library2 PROPERTIES LINKER_LANGUAGE CXX)