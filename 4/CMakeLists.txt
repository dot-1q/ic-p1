cmake_minimum_required(VERSION 2.8)
project( ci )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( ci copyImage.cpp )
target_link_libraries( ci ${OpenCV_LIBS} )
