cmake_minimum_required(VERSION 3.6)
project(Homework5)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "h5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        MainGame/Game.cpp MainGame/Game.h MainGame/GameObject.cpp MainGame/GameObject.h MainGame/RegularGameObject.cpp MainGame/RegularGameObject.h MainGame/AnimatedGameObject.cpp MainGame/AnimatedGameObject.h MainGame/MainMenu.cpp MainGame/MainMenu.h CutScenes/Background.cpp CutScenes/Background.h)

#copy file to where my executable is
file(COPY "content/Mario.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/bit.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Perfect DOS VGA 437.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/forest.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Silence-of-the-Forest.ogg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Kingdom_Hearts_Sound_EffectsSelect.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Kingdom_Hearts_Sound_EffectsCursor_Move.wav" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})