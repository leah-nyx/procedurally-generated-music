cmake_minimum_required(VERSION 3.26)
project(procedurally-generated-music VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    src/chords.cpp
    src/main.cpp
    src/player.cpp
)

add_subdirectory(external/libremidi/)

target_link_libraries(${PROJECT_NAME}
   PRIVATE
       libremidi::libremidi
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
