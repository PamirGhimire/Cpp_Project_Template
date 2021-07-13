# THIS_LIBRARY definition
add_library(
  source_lib
  Widget.cpp
)

target_include_directories(
  source_lib
  PUBLIC ${PROJECT_SOURCE_DIR}
)

set_target_properties(source_lib PROPERTIES LINKER_LANGUAGE CXX)