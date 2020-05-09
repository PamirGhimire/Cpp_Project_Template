# THIS_LIBRARY definition
add_library(
  source_lib
  class1.cpp
)

target_include_directories(
  source_lib
  PUBLIC ${PROJECT_SOURCE_DIR}
)

target_link_libraries(
  source_lib
  PRIVATE library1
  PRIVATE library2
)

set_target_properties(source_lib PROPERTIES LINKER_LANGUAGE CXX)