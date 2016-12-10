cmake_minimum_required(VERSION 3.5)
project(Homework5)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "h5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        CutScenes/Background.cpp
        CutScenes/Background.h
        MainGame/GameObject.cpp
        MainGame/GameObject.h
        MainGame/RegularGameObject.cpp
        MainGame/RegularGameObject.h
        MainGame/AnimatedGameObject.cpp
        MainGame/AnimatedGameObject.h
        MainGame/MainMenu.cpp
        MainGame/MainMenu.h
        MainGame/StageLevel.cpp
        MainGame/StageLevel.h
        MainGame/Slime.cpp
        MainGame/Slime.h
        MainGame/Instructions.cpp
        MainGame/Instructions.h MainGame/GameOver.cpp MainGame/GameOver.h)

#copy file to where my executable is
file(COPY "content/Mario.png" DESTINATION "${CMAKE_BINARY_DIR}")
# font files
file(COPY "AudioImages/bit.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Perfect DOS VGA 437.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
# mainMenu, instructions, game over - music/sound effects/BG image
file(COPY "AudioImages/Silence-of-the-Forest.ogg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Kingdom_Hearts_Sound_EffectsSelect.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Kingdom_Hearts_Sound_EffectsCursor_Move.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/quiet_slumber_instr.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/game_over.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/forest.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
# level music and pics
file(COPY "AudioImages/trap_queen_8bit_lv1.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/grassy_lands.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
# slime sound effects and images
file(COPY "AudioImages/jump.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/attack.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/get_item.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/slime_sprites.png" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})