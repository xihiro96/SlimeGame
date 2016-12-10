//
// Created by Randy Deng 12/9/16
//

#include "GameOver.h"

GameOver::GameOver(float width, float height) {
    // load in the music
    // gameOver sound
    if (!gameOverBuffer.loadFromFile("game_over.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // cursor selection sound
    if (!bufferSelect.loadFromFile("Kingdom_Hearts_Sound_EffectsSelect.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // set the game text
    if(!optionsFont.loadFromFile("bit.ttf")){
        //handle error
    }
    if(!titleFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        //handle error
    }
    // set the game over text
    gameOverText[0].setFont(titleFont);
    gameOverText[0].setFillColor(sf::Color::Red);
    gameOverText[0].setString("Game Over");
    gameOverText[0].setCharacterSize(100);
    gameOverText[0].setStyle(sf::Text::Bold);
    gameOverText[0].setPosition(width/3.0f, height/(MAX_NUM_ITEMS +1) * .7f);

    gameOverText[1].setFont(titleFont);
    gameOverText[1].setFillColor(sf::Color::White);
    gameOverText[1].setString("Press Enter");
    gameOverText[1].setCharacterSize(50);
    gameOverText[1].setStyle(sf::Text::Bold);
    gameOverText[1].setPosition(width/2.5f, height/(MAX_NUM_ITEMS +1) * 1.3f);
}

GameOver::~GameOver() {

}

void GameOver::playGameOverSound() {
    soundGameOver.setBuffer(gameOverBuffer);
    soundGameOver.play();
}

void GameOver::playSelectSound() {
    soundSelect.setBuffer(bufferSelect);
    soundSelect.play();
}

void GameOver::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(gameOverText[i]);
    }
}

void GameOver::runGameOver(sf::RenderWindow &window) {
    // create the gameOver screen
    GameOver gameOver(window.getSize().x, window.getSize().y);
    // play gameover sound
    gameOver.playGameOverSound();
    // FADE IN
    // define local variables
    int a;
    sf::RectangleShape fade;
    fade.setSize(sf::Vector2f(1280, 720));
    // fade in
    a = 255;
    fade.setFillColor(sf::Color(0,0,0,255));
    window.draw(fade);
    window.display();
    while(a > 0) {
        a -= 4;
        window.clear();
        gameOver.draw(window);
        window.draw(fade);
        fade.setFillColor(sf::Color(0,0,0,a));
        window.display();
    }
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
                        gameOver.playSelectSound();
                        // screen fade and return
                        a = 0;
                        while(a < 255) {
                            fade.setFillColor(sf::Color(0,0,0,a));
                            a++;
                            window.draw(fade);
                            window.display();
                        }
                        return;
                    }
            }
        }
        // clear and update the screen
        window.clear();
        gameOver.draw(window);
        window.display();
    }
}