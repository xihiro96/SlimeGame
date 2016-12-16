/*
 * Written by Randy Deng :) 12/8/16
 */

#include "MainGame/MainMenu.h"
#include "MainGame/Instructions.h"
#include "MainGame/StageLevel.h"
#include "MainGame/GameOver.h"
#include "CutScenes/Scene.h"
#include "MainGame/GameConfig.h"
#include "MainGame/StopWatch.h"

int main()
{

    // State Machine Controller
    // States: Main Menu, Game Levels, Instructions, Game Over, CutScenes
    enum gameState {mainMenu, playScene1, playScene2, playScene3, playScene4, playScene5, playScene6, playScene7,
        playScene8, playScene9, playScene10, playScene11, playGame, instructions, gameOver, cutScene};

    // Initialize menu
    sf::RenderWindow window(sf::VideoMode(1280,720), "Menu", sf::Style::Titlebar | sf::Style::Close);
    //Scene11::runScene11(window);
    // Initialize variables
    gameState currentState = mainMenu;
    int menuSelect;
    bool loopFlag = true;
    // create stopwatch and score
    static StopWatch<> sw;
    double score = 0;
    int val = -1; // check if next level or dead
    // initialize config file values
    Config gameData;
    GameConfig::loadConfig(gameData);
    GameConfig::gameReset(gameData);
    // begin loop here
    while(loopFlag) {
        switch(currentState) {
            case mainMenu :
                menuSelect = MainMenu::runMenu(window);

                // read button selected from MainMenu
                switch(menuSelect) {
                    case 0:
                        // play game

                        //currentState = gameOver;


                        currentState = playScene1;
                        break;
                    case 1:
                        // show instructions
                        currentState = instructions;
                        break;
                    case 2:
                        // exit game
                        loopFlag = false;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                break;
            case playScene1:
                Scene::runScene1(window);
                currentState = playScene2;
                break;
            case playScene2:
                Scene::runScene2(window);
                currentState = playScene3;
                break;
            case playScene3:
                Scene::runScene3(window);
                currentState = playScene4;
                break;
            case playScene4:
                Scene::runScene4(window);
                currentState = playScene5;
                break;
            case playScene5:
                Scene::runScene5(window);
                currentState = playScene6;
                break;
            case playScene6:
                Scene::runScene6(window);
                currentState = playScene7;
                break;
            case playScene7:
                Scene::runScene7(window);
                currentState = playScene8;
                break;
            case playScene8:
                Scene::runScene8(window);
                currentState = playScene9;
                break;
            case playScene9:
                Scene::runScene9(window);
                currentState = playScene10;
                break;
            case playScene10:
                Scene::runScene10(window);
                currentState = playScene11;
                break;
            case playScene11:
                Scene::runScene11(window);
                currentState = playGame;
                break;

            case playGame :
                // check which level user is on
                switch(gameData.level) {
                    case 1 :
                        // play level 1
                        sw.start();
                        val = StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 2 :
                        // play level 2
                        sw.start();
                        val = StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 3 :
                        // play level 3
                        sw.start();
                        val = StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 4 :
                        // play level 4
                        sw.start();
                        val = StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 5 :
                        sw.start();
                        val = StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        // play boss level
                        gameData.level++;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                    if (val == 0) {
                        currentState = gameOver;
                    } else if (val == 1) {
                        currentState = cutScene;
                    }
                    break;
            case instructions :
                Instructions::runMenu(window);
                currentState = mainMenu;
                break;
            case gameOver :
                GameOver::runMenu(window);
                // if user presses enter, go back to main screen and reset any game variables
                GameConfig::gameReset(gameData);
                currentState = mainMenu;
                break;
            case cutScene :
                // determine which cutscene to play
                switch(gameData.sceneNum) {
                    case 1 :
                        // play cutscene 1
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 2 :
                        // play cutscene 2
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 3 :
                        // play cutscene 3
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 4 :
                        //play custscene 4
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 5 :
                        //play custscene 5
                        gameData.sceneNum++;
                        // reset game variables and go back to menu
                        GameConfig::gameReset(gameData);
                        currentState = mainMenu;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                break;
            default:
                std::cout << "Error Error" << std::endl;
                loopFlag = false;
        }
    }
    return 0;
}