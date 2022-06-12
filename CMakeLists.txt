cmake_minimum_required(VERSION 3.16)
project(GuessThePath)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/win-builds/external_libs/SDL2/include)
set(SDL2_LIB_DIR C:/win-builds/external_libs/SDL2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(GuessThePath src/screen/Screen.cpp src/screen/Screen.h src/screen/WelcomeScreen.cpp src/screen/WelcomeScreen.h src/Game.cpp src/Game.h src/main.cpp src/assets/AssetsManager.cpp src/assets/AssetsManager.h src/assets/Asset.cpp src/assets/Asset.h)
set_property(TARGET GuessThePath PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/")

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_ttf)