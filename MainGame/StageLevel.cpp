//
// Created by Randy Deng on 12/8/16.
//

#include "StageLevel.h"

StageLevel::StageLevel(int levelNum) {
    // set background music depending on level
    // add platforms according to each level
    switch(levelNum) {
        case 1 :
            if (!levelMusic.openFromFile("trap_queen_8bit_lv1.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            gameObjects = {&plat1, &plat2, &plat3, &plat4};
            xPos = {300, 550, 750, 500};
            yPos = {450, 350, 250, 150};
            plat1.load("longPlat2.png");
            plat2.load("longPlat2.png");
            plat3.load("longPlat2.png");
            plat4.load("longPlat2.png");
            for (int i = 0; i < xPos.size(); i++) {
                gameObjects[i]->setPosition(xPos[i], yPos[i]);
            }
            winItem.load("herb.png");
            winItem.setScale(0.2f);
            winItem.setPosition(500, 120);
            winx = 500;
            winy = 120;
            break;
        case 2 :
            if (!levelMusic.openFromFile("panda_8bit_lv2.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            gameObjects = {&plat1, &plat2, &plat3, &plat4, &plat5};
            xPos = {300, 550, 750, 1070, 1200};
            yPos = {450, 350, 250, 290, 230};
            plat1.load("longPlat2.png");
            plat2.load("longPlat2.png");
            plat3.load("longPlat2.png");
            plat4.load("shortPlat2.png");
            plat5.load("shortPlat2.png");
            for (int i = 0; i < xPos.size(); i++) {
                gameObjects[i]->setPosition(xPos[i], yPos[i]);
            }
            winItem.load("skin.png");
            winItem.setScale(0.2f);
            winItem.setPosition(1200, 180);
            winx = 1200;
            winy = 180;
            break;
        case 3 :
            if (!levelMusic.openFromFile("radioactive_8bit_lv3.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            gameObjects = {&plat1, &plat2, &plat3, &plat4, &plat5, &plat6, &plat7};
            xPos = {300, 50, 350, 800, 700, 1100, 1200};
            yPos = {450, 300, 150, 200, 150, 300, 300};
            plat1.load("longPlat3.png");
            plat2.load("longPlat3.png");
            plat3.load("longPlat3.png");
            plat4.load("longPlat3.png");
            plat5.load("shortPlat3.png");
            plat6.load("shortPlat3.png");
            plat7.load("shortPlat3.png");
            for (int i = 0; i < xPos.size(); i++) {
                gameObjects[i]->setPosition(xPos[i], yPos[i]);
            }
            winItem.load("water.png");
            winItem.setScale(0.25f);
            winItem.setPosition(1200, 260);
            winx = 1200;
            winy = 260;
            break;
        case 4 :
            if (!levelMusic.openFromFile("heathens_8bit_lv4.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            xPos = {100, 300, 500, 700, 850, 900, 1000, 1100};
            yPos = {500, 450, 400, 300, 200, 150, 100, 50};
            plat1.load("longPlat4.png");
            plat2.load("longPlat4.png");
            plat3.load("longPlat4.png");
            plat4.load("longPlat4.png");
            plat5.load("shortPlat4.png");
            plat6.load("shortPlat4.png");
            plat7.load("shortPlat4.png");
            plat8.load("shortPlat4.png");
            gameObjects = {&plat1, &plat2, &plat3, &plat4, &plat5, &plat6, &plat7, &plat8};
            for (int i = 0; i < xPos.size(); i++) {
                gameObjects[i]->setPosition(xPos[i], yPos[i]);
            }
            winItem.load("bones.png");
            winItem.setScale(0.2f);
            winItem.setPosition(1100, 20);
            winx = 1100;
            winy = 20;
            break;
        case 5 :
            if (!levelMusic.openFromFile("sao_8bit_lv5.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            xPos = {100, 300, 500, 800, 900, 1100};
            yPos = {450, 350, 250, 150, 50, 350};
            plat1.load("longPlat4.png");
            plat2.load("longPlat4.png");
            plat3.load("longPlat4.png");
            plat4.load("shortPlat4.png");
            plat5.load("shortPlat4.png");
            plat6.load("shortPlat4.png");
            gameObjects = {&plat1, &plat2, &plat3, &plat4, &plat5, &plat6};
            for (int i = 0; i < xPos.size(); i++) {
                gameObjects[i]->setPosition(xPos[i], yPos[i]);
            }
            winItem.load("portal.png");
            winItem.setScale(0.6f);
            winItem.setPosition(1100, 320);
            winx = 1100;
            winy = 320;
            break;
        default :
        std::cout << "error" << std::endl;
    }
    levelMusic.setLoop(true);
}

StageLevel::~StageLevel() {

}

void StageLevel::smartMove(Slime &player, sf::RenderWindow &window, sf::Vector2f &movement, float m_speed, bool direction) {
    // check for window collision
    while(player.getPosition().x > window.getSize().x - 90 || player.getPosition().x <= - 40) {
        while(player.getPosition().x > window.getSize().x - 90) {
            movement.x = -m_speed;
            player.move(movement);
        }
        while(player.getPosition().x <= -40) {
            movement.x = m_speed;
            player.move(movement);
        }
    }
    // move normally
    if (direction) {
        movement.x = m_speed;
        player.move(movement);
    } else {
        movement.x = -m_speed;
        player.move(movement);
    }
}

// Collision checking + other checking
bool StageLevel::checkCollisions(Slime &player, int &plat) {
    int mX = 55;
    int mY = 80;
    for (int i = 0; i < gameObjects.size(); i++) {
        if(player.getPosition().x > xPos[i] - mX
           && player.getPosition().x < xPos[i] + gameObjects[i]->getWidth() - mX
           && player.getPosition().y > yPos[i]
           && player.getPosition().y < yPos[i]+ gameObjects[i]->getHeight()){
            // specify platform value
            plat = yPos[i] - mY;
            // on a platform
            return true;
        }
    }
    // not on a platform
    return false;
}
void StageLevel::checkGround(Slime &player) {
    // if below ground, put on ground
    if (player.getPosition().y > 500.0f) {
        player.setPosition(player.getPosition().x, 500.0f);
    }
}

// Check winning/dying conditions
int StageLevel::checkWinDead(Slime &player) {
    int mX = 80;
    int mY = 80;
    // check win condition
    if(player.getPosition().x > winx - mX
       && player.getPosition().x < winx + mX
       && player.getPosition().y > winy - mY
       && player.getPosition().y < winy + mY) {
        return 1;
    } //else {return -1;}
    // check dead condition
    if(player.getPosition().x > 900
        && player.getPosition().x < 1300
        && player.getPosition().y > 450
        && player.getPosition().y < 550) {
        return 0;
    } else {return -1;}
}

// drawing functions

void StageLevel::draw(sf::RenderWindow &window) {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i] -> draw(window);
    }
}
void StageLevel::render(sf::RenderWindow& window, sf::RectangleShape& background, Slime& player, StageLevel& level) {
    // clear and update the screen
    window.clear();
    window.draw(background);
    // update
    player.draw(window);
    player.update(32, 32*9);
    level.draw(window);
    winItem.draw(window);
    window.display();
}

void StageLevel::playLevelMusic() {
    levelMusic.play();
}

int StageLevel::runLevel(sf::RenderWindow &window, int levelNum) {
    // set main menu screen and background
    StageLevel level(levelNum);
    Background back;
    back.setBack(levelNum);
    sf::RectangleShape backgroundIm = back.createBackground(back.getBack(), sf::Vector2f(window.getSize().x, window.getSize().y));
    // play music
    level.playLevelMusic();
    // set m_speed and slime
    float m_speed = /*15*/10.0f, j_speed = /*100*/150.0f, gravity = /*20*/1.0f;
    Slime player(levelNum);
    bool isJumping = false;
    bool direction;
    // height of platform currently on
    int plat;
    // read key presses
    while(window.isOpen()) {
        // set up events and clocks
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
            sf::Vector2f movement(0.0f, 0.0f);
            while(isJumping){
                // check if character is on platform
                isJumping = !level.checkCollisions(player, plat) && player.getPosition().y < 500.0f;
                //if on platform, set y position to be platform height
                if (level.checkCollisions(player, plat)) {
                    player.setPosition(player.getPosition().x, plat);
                    isJumping = false;
                    break;
                }
                // if not, apply gravity
                movement.y += gravity;
                // check for key presses to move in x
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    direction = false;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    direction = true;
                }
                else{
                    direction = NULL; //jumping in place
                }
                if (direction != NULL){
                    level.smartMove(player, window, movement, m_speed, direction);
                }
                else { //don't do smart move if jumping in place
                    player.move(movement);
                }
                level.render(window, backgroundIm, player, level);
            }
            // check if below ground
            level.checkGround(player);
            // check normal button presses
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                isJumping = false;
                level.smartMove(player, window, movement, m_speed, false);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                isJumping = false;
                level.smartMove(player, window, movement, m_speed, true);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                player.playAttackSound();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                //pause
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                //continuously jumps in place if W is held down
                isJumping = true;
                player.playJumpSound();
                movement.y = -j_speed;
                player.move(movement);
            }
        }
        // check win or dead condition
        if (level.checkWinDead(player) == 1) {
            // win
            return 1;
        } else if (level.checkWinDead(player) == 0) {
            // dead
            return 0;
        }
        level.render(window, backgroundIm, player, level);
    }
}