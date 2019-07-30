cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(hellotriangle src/hellotriangle.cpp)
add_executable(hellotriangle-problems src/hellotriangle-problems.cpp)
add_executable(EBO src/EBO.cpp)
add_executable(shaders-problems src/shaders-problems.cpp)
add_executable(textures src/textures.cpp src/stb_image.cpp)
add_executable(transformations src/transformations.cpp src/stb_image.cpp)

include_directories(/usr/include/SFML)
include_directories(/usr/include/GL)
include_directories(/usr/include/glm)
include_directories(/usr/include/glm/gtc)
include_directories(include)

target_link_libraries(hellotriangle LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)
target_link_libraries(hellotriangle-problems LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)
target_link_libraries(EBO LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)
target_link_libraries(shaders-problems LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)
target_link_libraries(textures LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)
target_link_libraries(transformations LINK_PUBLIC GL GLEW sfml-graphics sfml-window sfml-system)