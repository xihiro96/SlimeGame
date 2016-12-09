/*
 * Written by Randy Deng :) 12/8/16
 */

#include "MainGame/MainMenu.h"
#include "MainGame/StageLevel.h"

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
    int sceneNum = 1;
    int level = 1;

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
                switch(level) {
                    case 1 :
                        // play level 1
                        StageLevel::runLevel(window);
                        level++;
                        break;
                    case 2 :
                        // play level 2
                        level++;
                        break;
                    case 3 :
                        // play level 3
                        level++;
                        break;
                    case 4 :
                        // play level 4
                        level++;
                        break;
                    case 5 :
                        // play boss level
                        level++;
                        break;
                    default :
                        std::cout << "Error Error" << std::endl;
                        loopFlag = false;
                }
                std::cout << "Play button has been pressed" << std::endl;

                // remove this once game is implemented ******
                currentState = mainMenu;
                //loopFlag = false;
                //********************************************

                break;
            case instructions :
                // TODO display instructions page
                std::cout << "Instructions has been selected" << std::endl;

                // remove this once game is implemented ******
                currentState = mainMenu;
                //********************************************

                break;
            case gameOver :
                // TODO display gameover screen
                // if user presses any key, go back to main screen and reset any game variables

                // remove this once game is implemented ******
                currentState = mainMenu;
                //********************************************

                break;
            case cutScene :
                // TODO play cutScenes based on cutScene number :)
                // determine which cutscene to play
                switch(sceneNum) {
                    case 1 :
                        // play cutscene 1
                        sceneNum++;
                        break;
                    case 2 :
                        sceneNum++;
                        break;
                    case 3 :
                        sceneNum++;
                        break;
                    case 4 :
                        sceneNum++;
                        break;
                    case 5 :
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