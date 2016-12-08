//
// Created by marites on 12/3/16.
//

#include "MainMenu.h"
#include "../CutScenes/Background.h"

MainMenu::MainMenu(float width, float height) {

    if(!optionsFont.loadFromFile("bit.ttf")){
        //handle error
    }
    if(!titleFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        //handle error
    }
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

MainMenu::~MainMenu() {

}

void MainMenu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void MainMenu::moveUp() {
    if(selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}
void MainMenu::moveDown() {
    if(selectedItemIndex + 2 < MAX_NUM_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        menu[selectedItemIndex].setCharacterSize(30);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Green);
        menu[selectedItemIndex].setCharacterSize(40);
    }
}

void MainMenu::playCursorSound() {
    if (!bufferCursor.loadFromFile("Kingdom_Hearts_Sound_EffectsCursor_Move.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    soundCursor.setBuffer(bufferCursor);
    soundCursor.play();
}

void MainMenu::playSelectSound() {
    if (!bufferSelect.loadFromFile("Kingdom_Hearts_Sound_EffectsSelect.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    soundSelect.setBuffer(bufferSelect);
    soundSelect.play();
}

void MainMenu::playMenuMusic() {
    if (!menuMusic.openFromFile("Silence-of-the-Forest.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    menuMusic.play();
}

void MainMenu::runMenu() {
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Menu");
    MainMenu menu(window.getSize().x, window.getSize().y);

    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest.jpg", sf::Vector2f(1920, 1080));

    menu.playMenuMusic();


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            menu.playCursorSound();
                            break;

                        case sf::Keyboard::Down:
                            menu.moveDown();
                            menu.playCursorSound();
                            break;
                        case sf::Keyboard::Return:
                            menu.playSelectSound();
                            switch (menu.getPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "Instructions has been selected" << std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }
                    }

            }
        }


        window.clear();
        window.draw(backgroundIm);
        menu.draw(window);
        window.display();
    }




}