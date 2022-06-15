cmake_minimum_required(VERSION 3.16)
project(GuessThePath)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/win-builds/external_libs/SDL2/include)
set(SDL2_LIB_DIR C:/win-builds/external_libs/SDL2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(GuessThePath src/ui/screen/Screen.cpp src/ui/screen/Screen.h src/ui/screen/WelcomeScreen.cpp src/ui/screen/WelcomeScreen.h src/Game.cpp src/Game.h src/main.cpp src/assets/AssetsManager.cpp src/assets/AssetsManager.h src/assets/Asset.cpp src/assets/Asset.h src/ui/screen/MenuScreen.cpp src/ui/screen/MenuScreen.h src/ui/Renderable.cpp src/ui/Renderable.h src/ui/Button.cpp src/ui/Button.h src/ui/Text.cpp src/ui/Text.h src/ui/TextField.cpp src/ui/TextField.h src/ui/text/TitleText.cpp src/ui/text/TitleText.h src/ui/text/InfoText.cpp src/ui/text/InfoText.h src/ui/Defaults.h src/ui/screen/HelpScreen.cpp src/ui/screen/HelpScreen.h src/ui/button/PlayButton.cpp src/ui/button/PlayButton.h src/ui/button/BackButton.cpp src/ui/button/BackButton.h src/ui/screen/GameScreen.cpp src/ui/screen/GameScreen.h src/ui/button/ExitButton.cpp src/ui/button/ExitButton.h src/ui/button/HelpButton.cpp src/ui/button/HelpButton.h src/ui/screen/SwitchPlayerScreen.cpp src/ui/screen/SwitchPlayerScreen.h src/ui/button/SwitchPlayerButton.cpp src/ui/button/SwitchPlayerButton.h src/ui/button/RecordsButton.cpp src/ui/button/RecordsButton.h src/ui/screen/RecordsScreen.cpp src/ui/screen/RecordsScreen.h src/ui/button/ApplyUsernameButton.cpp src/ui/button/ApplyUsernameButton.h src/game/map/Map.cpp src/game/map/Map.h src/game/map/cell/Cell.cpp src/game/map/cell/Cell.h src/game/map/Player.cpp src/game/map/Player.h src/game/map/cell/Finish.cpp src/game/map/cell/Finish.h src/game/map/cell/Bomb.cpp src/game/map/cell/Bomb.h src/game/map/cell/EmptyPath.cpp src/game/map/cell/EmptyPath.h src/Utils.cpp src/Utils.h)
set_property(TARGET GuessThePath PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/")

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_ttf)