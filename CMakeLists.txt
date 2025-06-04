set(bin "bin/")
set(sfml_include "lib/SFML-2.6.1/include/")
set(src_include "src/include/")
set(SFML_LIB_DIR "lib/SFML-2.6.1/lib/")
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
set(classes "src/classes/")
set(game "AsteroidMadness")

cmake_minimum_required(VERSION 3.28.3)
project(AsteroidMadnessGame)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin})
include_directories(${CMAKE_SOURCE_DIR}/${sfml_include} ${CMAKE_SOURCE_DIR}/${src_include})
link_directories(${CMAKE_SOURCE_DIR}/${SFML_LIB_DIR})
file(GLOB cpp_files "${classes}*.cpp")
add_executable(${game} ${cpp_files})
target_link_libraries(${game} PRIVATE ${SFML_LIBS} openal)



