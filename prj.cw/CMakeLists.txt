include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set( OpenCV_DIR "C:/Users/vanyu/Documents/libraries/opencv")
find_package(OpenCV REQUIRED)
if( OpenCV_FOUND )
  include_directories( ${OpenCV_INCLUDE_DIRS} )
  link_directories( ${OpenCV_LIB_DIR} )
endif()

add_library(open open.cpp open.hpp)
target_link_libraries(open ${OpenCV_LIBS})
set_property(TARGET open PROPERTY CXX_STANDARD 20)
target_include_directories(open PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

add_library(graphics graphics.cpp graphics.hpp)
target_link_libraries(graphics open)
target_link_libraries(graphics sfml-graphics)
target_link_libraries(graphics sfml-window)
set_property(TARGET graphics PROPERTY CXX_STANDARD 20)
target_include_directories(graphics PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

add_executable(project_main main.cpp)
target_link_libraries(project_main graphics)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT project_main)