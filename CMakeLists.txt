cmake_minimum_required(VERSION 3.22)

project(vuture VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(vuture app/main.cpp)

add_subdirectory(lib/glfw)
# add_subdirectory(lib/glm)

include(OpenGLContent)

find_and_link(OpenGL)
find_and_link(GLEW)

target_link_libraries(vuture glfw OpenGL::GL GLEW)