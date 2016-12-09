//
// Created by marites on 12/3/16.
//

#include "MainMenu.h"


MainMenu::MainMenu(float width, float height) {
    // create the sounds once
    // cursor movement sound
    if (!bufferCursor.loadFromFile("Kingdom_Hearts_Sound_EffectsCursor_Move.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // cursor selection sound
    if (!bufferSelect.loadFromFile("Kingdom_Hearts_Sound_EffectsSelect.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // background music sound
    if (!menuMusic.openFromFile("Silence-of-the-Forest.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    menuMusic.setLoop(true);

    // set the game text
    if(!optionsFont.loadFromFile("bit.ttf")){
        //handle error
    }
    if(!titleFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        //handle error
    }
    menu[0].setFont(optionsFont);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Begin Game");
    menu[0].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 1.5f);
    menu[0].setCharacterSize(40);

    menu[1].setFont(optionsFont);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Instructions");
    menu[1].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 2.5f);

    menu[2].setFont(optionsFont);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 3.5f);

    menu[3].setFont(titleFont);
    menu[3].setFillColor(sf::Color::Green);
    menu[3].setString("Slime Adventures");
    menu[3].setCharacterSize(75);
    menu[3].setStyle(sf::Text::Bold);
    menu[3].setPosition(width/10, height/(MAX_NUM_ITEMS +1) * .3f);

    selectedItemIndex = 0;

}

MainMenu::~MainMenu() {

}

void MainMenu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

// change text visuals when moving up
void MainMenu::moveUp() {
    if(selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}

// change text visuals when moving down
void MainMenu::moveDown() {
    if(selectedItemIndex + 2 < MAX_NUM_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}

void MainMenu::playCursorSound() {
    soundCursor.setBuffer(bufferCursor);
    soundCursor.play();
}

void MainMenu::playSelectSound() {
    soundSelect.setBuffer(bufferSelect);
    soundSelect.play();
}

void MainMenu::playMenuMusic() {
    menuMusic.play();
}

int MainMenu::runMenu(sf::RenderWindow &window) {
    // set main menu screen
    MainMenu menu(window.getSize().x, window.getSize().y);
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest.jpg", sf::Vector2f(1280,720));
    // play music
    menu.playMenuMusic();

    // read key presses
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                // read which key was released (up/down)
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        // move up
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            menu.playCursorSound();
                            break;
                        // move down
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            menu.playCursorSound();
                            break;
                        // read which button was pressed and return value
                        case sf::Keyboard::Return:
                            menu.playSelectSound();
                            // screen fade and return
                            sf::RectangleShape fade;
                            fade.setSize(sf::Vector2f(1280, 720));
                            int a = 0;
                            while(a < 255) {
                                fade.setFillColor(sf::Color(0,0,0,a));
                                a++;
                                window.draw(fade);
                                window.display();
                            }
                        return menu.getPressedItem();
                    }
                }
            }
            // clear and update the screen
            window.clear();
            window.draw(backgroundIm);
            menu.draw(window);
            window.display();
        }
    }