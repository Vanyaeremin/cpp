set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "C:/Users/vanyu/Documents/libraries/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS graphics window system)

add_library(graphicslib STATIC graphics.cpp graphics.hpp)

if(SFML_FOUND)
	target_link_libraries(graphicslib sfml-graphics sfml-window)
else() 
	message(WARNING "SFML NOT FOUND")
endif()

target_link_libraries(graphicslib openlib)
set_property(TARGET graphicslib PROPERTY CXX_STANDARD 20)
target_include_directories(graphicslib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
