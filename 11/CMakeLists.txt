cmake_minimum_required(VERSION 2.8)
project( snr )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( snr imageSNR.cpp )
target_link_libraries( snr ${OpenCV_LIBS} )
