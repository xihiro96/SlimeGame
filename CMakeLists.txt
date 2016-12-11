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
        MainGame/Instructions.h
        MainGame/GameOver.cpp
        MainGame/GameOver.h
        MainGame/MenuItems.cpp
        MainGame/MenuItems.h)

#copy file to where my executable is
# font files
file(COPY "AudioImages/Fonts/bit.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/Fonts/Perfect DOS VGA 437.ttf" DESTINATION "${CMAKE_BINARY_DIR}")
# MenuItems music and pics
file(COPY "AudioImages/MenuItems/Silence-of-the-Forest.ogg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/MenuItems/Kingdom_Hearts_Sound_EffectsSelect.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/MenuItems/Kingdom_Hearts_Sound_EffectsCursor_Move.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/MenuItems/quiet_slumber_instr.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/MenuItems/game_over.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/MenuItems/forest.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
# level music and pics
file(COPY "AudioImages/GameLevels/trap_queen_8bit_lv1.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/panda_8bit_lv2.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/radioactive_8bit_lv3.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/heathens_8bit_lv4.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/sao_8bit_lv5.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/forest_back.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/Plains_back.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/ocean_back.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/volcano_back.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameLevels/cave_back.png" DESTINATION "${CMAKE_BINARY_DIR}")
# slime sound effects and images
file(COPY "AudioImages/GameSprites/Slime/jump.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/attack.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/get_item.wav" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/caveSlime.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/fireSlime.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/forestSlime.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/plainSlime.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "AudioImages/GameSprites/Slime/waterSlime.png" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})