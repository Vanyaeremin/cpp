add_library(openlib STATIC open.cpp open.hpp)

find_package(OpenCV)
if( OpenCV_FOUND )
  include_directories( ${OpenCV_INCLUDE_DIRS} )
  link_directories( ${OpenCV_LIB_DIR} )
  target_link_libraries(openlib ${OpenCV_LIBS})
else() 
	message(WARNING "OPENCV NOT FOUND")
endif()

set_property(TARGET openlib PROPERTY CXX_STANDARD 20)
target_include_directories(openlib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

