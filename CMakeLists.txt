cmake_minimum_required(VERSION 3.3)
project(max_contour)
find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SOURCE_FILES main.cpp)
add_executable(max_contour ${SOURCE_FILES})
target_link_libraries( max_contour ${OpenCV_LIBS} )

