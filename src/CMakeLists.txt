include_directories(../include)
add_library(ppm ppm.cpp)
add_library(geometry geometry.cpp)
target_link_libraries(ppm geometry)