add_subdirectory(graphics)
add_subdirectory(open)

add_executable(project_main main.cpp)
target_link_libraries(project_main graphicslib)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT project_main)