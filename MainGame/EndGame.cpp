//
// Created by Randy Deng 12/9/16
//

#include "EndGame.h"

EndGame::EndGame(float width, float height, double score) {
    std::string sc = std::to_string(score);
    sc = sc.substr(0, 4);
    // set the game over text
    gameOverText[0].setFont(titleFont);
    gameOverText[0].setColor(sf::Color::Green);
    gameOverText[0].setString("Score: " + sc + " seconds");
    gameOverText[0].setCharacterSize(100);
    gameOverText[0].setStyle(sf::Text::Bold);
    gameOverText[0].setPosition(width/7.5f - 20, height/(MAX_NUM_ITEMS +1) * .7f);

    gameOverText[1].setFont(titleFont);
    gameOverText[1].setColor(sf::Color::White);
    gameOverText[1].setString("Press Enter");
    gameOverText[1].setCharacterSize(50);
    gameOverText[1].setStyle(sf::Text::Bold);
    gameOverText[1].setPosition(width/2.5f, height/(MAX_NUM_ITEMS +1) * 1.3f);
}

void EndGame::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(gameOverText[i]);
    }
}

void EndGame::runMenu(sf::RenderWindow &window, double score) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    EndGame gameOver(screenX, screenY, score);
    // set background
    sf::RectangleShape backgroundIm(sf::Vector2f(screenX, screenY));
    backgroundIm.setFillColor(sf::Color::Black);
    // fade in
    gameOver.fadeIn(window, gameOver, backgroundIm);
    // loop to check for key presses
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        // screen fade and return
                        gameOver.playSelectSound();
                        gameOver.fadeOut(window);
                        return;
                    }
            }
        }
        // clear and update the screen
        gameOver.render(window, gameOver, backgroundIm);
    }
}