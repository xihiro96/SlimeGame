//
// Created by marites on 12/3/16.
//

#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) : MenuItems() {
    menu[0].setFont(optionsFont);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Begin Game");
    menu[0].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 1.5f);
    menu[0].setCharacterSize(40);

    menu[1].setFont(optionsFont);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Instructions");
    menu[1].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 2.5f);

    menu[2].setFont(optionsFont);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 3.5f);

    menu[3].setFont(titleFont);
    menu[3].setColor(sf::Color::Green);
    menu[3].setString("Slime Adventures");
    menu[3].setCharacterSize(75);
    menu[3].setStyle(sf::Text::Bold);
    menu[3].setPosition(width/10, height/(MAX_NUM_ITEMS +1) * .3f);

    selectedItemIndex = 0;
}

void MainMenu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

// change text visuals when moving up
void MainMenu::moveUp() {
    if(selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}

// change text visuals when moving down
void MainMenu::moveDown() {
    if(selectedItemIndex + 2 < MAX_NUM_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}

int MainMenu::runMenu(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // set main menu screen
    MainMenu menu(screenX, screenY);
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest.jpg", sf::Vector2f(screenX, screenY));
    // play music
    menu.playMenuMusic();
    // fade in
    menu.fadeIn(window, menu, backgroundIm);
    // read key presses
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                // read which key was released (up/down)
                case sf::Event::KeyReleased :
                    switch (event.key.code) {
                        // move up

                        case sf::Keyboard::W:

                        case sf::Keyboard::Up :

                            menu.moveUp();
                            menu.playCursorSound();
                            break;
                        // move down

                        case sf::Keyboard::S:

                        case sf::Keyboard::Down :

                            menu.moveDown();
                            menu.playCursorSound();
                            break;
                        // read which button was pressed and return value
                        case sf::Keyboard::Return :
                            // screen fade and return
                            menu.playSelectSound();
                            menu.fadeOut(window);
                            return menu.getPressedItem();
                    }
                }
            }
        // clear and update the screen
        menu.render(window, menu, backgroundIm);
        }
    }