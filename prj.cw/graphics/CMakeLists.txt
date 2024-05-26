set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "C:/Users/vanyu/Documents/libraries/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

add_library(graphicslib STATIC graphics.cpp graphics.hpp)
target_link_libraries(graphicslib openlib sfml-graphics sfml-window)
set_property(TARGET graphicslib PROPERTY CXX_STANDARD 20)
target_include_directories(graphicslib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
