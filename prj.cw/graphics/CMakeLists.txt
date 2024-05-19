include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_library(graphicslib graphics.cpp graphics.hpp)
target_link_libraries(graphicslib openlib)
target_link_libraries(graphicslib sfml-graphics)
target_link_libraries(graphicslib sfml-window)
set_property(TARGET graphicslib PROPERTY CXX_STANDARD 20)
target_include_directories(graphicslib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
