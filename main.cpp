/*
 * Written by Randy Deng :) 12/8/16
 */

#include "MainGame/MainMenu.h"
#include "MainGame/Instructions.h"
#include "MainGame/StageLevel.h"
#include "MainGame/GameOver.h"
#include "MainGame/EndGame.h"
#include "CutScenes/Scene.h"
#include "MainGame/GameConfig.h"
#include "MainGame/StopWatch.h"

int main()
{

    // State Machine Controller
    // States: Main Menu, Game Levels, Instructions, Game Over, CutScenes, endGame
    enum gameState {mainMenu, playGame, instructions, gameOver, cutScene, endGame};

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
                        currentState = cutScene;
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
                        Scene::runScene1(window);
                        Scene::runScene2(window);
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 2 :
                        // play cutscene 2
                        Scene::runScene3(window);
                        Scene::runScene4(window);
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 3 :
                        // play cutscene 3
                        Scene::runScene5(window);
                        Scene::runScene6(window);
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 4 :
                        //play custscene 4
                        Scene::runScene7(window);
                        Scene::runScene8(window);
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 5 :
                        //play custscene 5
                        Scene::runScene9(window);
                        Scene::runScene10(window);
                        gameData.sceneNum++;
                        currentState = playGame;
                        break;
                    case 6 :
                        // play end
                        Scene::runScene11(window);
                        // reset game variables and go back to menu
                        currentState = endGame;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                break;
            case endGame :
                // reset game, record score, show end screen
                GameConfig::gameReset(gameData);
                if(score < gameData.highScore) {
                    gameData.highScore = score;
                    GameConfig::writeConfig(gameData);
                }
                EndGame::runMenu(window, score);
                score = 0;
                currentState = mainMenu;
                break;
            default:
                std::cout << "Error Error" << std::endl;
                loopFlag = false;
        }
    }
    return 0;
}