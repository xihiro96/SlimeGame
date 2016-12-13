/*
 * Written by Randy Deng :) 12/8/16
 */

#include "MainGame/MainMenu.h"
#include "MainGame/Instructions.h"
#include "MainGame/StageLevel.h"
#include "MainGame/GameOver.h"
#include "MainGame/GameConfig.h"
#include "MainGame/StopWatch.h"

int main()
{
    // State Machine Controller
    // States: Main Menu, Game Levels, Instructions, Game Over, CutScenes
    enum gameState {mainMenu, playGame, instructions, gameOver, cutScene};

    // Forward declaration of functions
    // so far there's none :)

    // Initialize menu
    sf::RenderWindow window(sf::VideoMode(1280,720), "Menu", sf::Style::Titlebar | sf::Style::Close);

    // Initialize variables
    gameState currentState = mainMenu;
    int menuSelect;
    bool loopFlag = true;
    // create stopwatch and score
    static StopWatch<> sw;
    double score = 0;
    // initialize config file values
    Config gameData;
    GameConfig::loadConfig(gameData);
    //GameConfig::gameReset(gameData);
    // TODO fix issues with writeConfig.... it has to do with the working directory
    //GameConfig::writeConfig(gameData);

    // begin loop here
    while(loopFlag) {
        switch(currentState) {
            case mainMenu :
                menuSelect = MainMenu::runMenu(window);
                // read button selected from MainMenu
                switch(menuSelect) {
                    case 0:
                        // play game
                        currentState = playGame;
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
                // TODO create all of the game logic... woooo
                // check which level user is on
                switch(gameData.level) {
                    case 1 :
                        // play level 1
                        sw.start();
                        StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 2 :
                        // play level 2
                        sw.start();
                        StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 3 :
                        // play level 3
                        sw.start();
                        StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 4 :
                        // play level 4
                        sw.start();
                        StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        gameData.level++;
                        break;
                    case 5 :
                        sw.start();
                        StageLevel::runLevel(window, gameData.level);
                        score += sw.stop();
                        // play boss level
                        gameData.level++;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                // remove this once game is implemented ******
                currentState = mainMenu;
                //loopFlag = false;
                //********************************************

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
                // TODO play cutScenes based on cutScene number :)
                // determine which cutscene to play
                switch(gameData.sceneNum) {
                    case 1 :
                        // play cutscene 1
                        gameData.sceneNum++;
                        break;
                    case 2 :
                        // play cutscene 2
                        gameData.sceneNum++;
                        break;
                    case 3 :
                        // play cutscene 3
                        gameData.sceneNum++;
                        break;
                    case 4 :
                        //play custscene 4
                        gameData.sceneNum++;
                        break;
                    case 5 :
                        //play custscene 5
                        gameData.sceneNum++;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }

                // remove this once game is implemented ******
                currentState = mainMenu;
                //********************************************

                break;
            default:
                std::cout << "Error Error" << std::endl;
                loopFlag = false;
        }
    }
    return 0;
}