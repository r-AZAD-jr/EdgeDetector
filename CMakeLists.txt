cmake_minimum_required(VERSION 3.10.2)

project(edge_detection)
set(TARGET_NAME ${PROJECT_NAME})

#find_package()  uncomment and fill this if you want to use any external libraries

file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(
	include EdgeDetector.hpp
	include EdgeDetector.cpp
)

set(SOURCES ${CPP_FILES})
add_library(TARGET_NAME SHARED ${SOURCES} /usr/local/lib)
target_include_directories(TARGET_NAME PUBLIC ${INCLUDE_DIRECTORIES} /usr/local/include/opencv4)
target_link_libraries(TARGET_NAME opencv_imgproc opencv_imgcodecs opencv_core opencv_highgui)

add_executable(edge_detection_bin src/EdgeDetector.cpp )
target_include_directories(edge_detection_bin PUBLIC ${INCLUDE_DIRECTORIES} )
target_link_libraries(edge_detection_bin TARGET_NAME)
