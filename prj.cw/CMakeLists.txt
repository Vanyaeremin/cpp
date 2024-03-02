add_executable(opencv_pr1 opencv_pr1.cpp)

set( OpenCV_DIR "C:/Users/vanyu/Documents/libraries/opencv" )

find_package(OpenCV REQUIRED)

if( OpenCV_FOUND )
  include_directories( ${OpenCV_INCLUDE_DIRS} )

  link_directories( ${OpenCV_LIB_DIR} )

  target_link_libraries( opencv_pr1 ${OpenCV_LIBS} )
endif()


