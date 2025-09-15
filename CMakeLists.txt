cmake_minimum_required(VERSION 3.16)
project(cpp-game-prac LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL3_ROOT "${CMAKE_SOURCE_DIR}/external/SDL3-3.2.22")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(_SDL_TRIPLET "x86_64-w64-mingw32")
else()
    set(_SDL_TRIPLET "i686-w64-mingw32")
endif()

set(SDL3_DIR "${SDL3_ROOT}/${_SDL_TRIPLET}/lib/cmake/SDL3")

find_package(SDL3 CONFIG REQUIRED)

add_executable(game
    "${CMAKE_SOURCE_DIR}/src/Game.cpp"
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
)

target_include_directories(game PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(game PRIVATE SDL3::SDL3)

install(TARGETS game
    RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin"
)

install(FILES
    "${SDL3_ROOT}/${_SDL_TRIPLET}/bin/SDL3.dll"
    DESTINATION "${CMAKE_SOURCE_DIR}/bin"
)
