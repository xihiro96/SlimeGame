//
// Created by marites on 12/12/16.
//

#include "Scene.h"
#include "Background.h"
#include "../MainGame/Slime.h"


Scene::Scene(float width, float height) {

}

void Scene::draw(sf::RenderWindow &window) {
    /*for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(text[i]);
    }*/
}
std::vector<std::string> Scene::createStrings(std::string line){
    int len = line.length();
    std::vector<std::string> text;
    if(len >70) {
        std::string sub1= line.substr(71,len);
        text.push_back(line.substr(0,70));
        text.push_back(sub1);
    }
    text.push_back(line);
    return text;
}

void Scene::runScene1(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject hoodedFigure;
    AnimatedGameObject happySlime;
    Slime slimeBit(1);
    sf::Music forestSounds;

    hoodedFigure.load("hoodFig2.png");
    happySlime.load("slime_normal_right.png");
    hoodedFigure.setScale(1.7f);
    happySlime.setScale(.9f);
    hoodedFigure.setCrop(0,0, 231, 300);
    hoodedFigure.setPosition(1200, 150); //950, 150
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forestCave.jpg", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 540));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    // loop to check for key presses
    std::string line1 = "...And the people lived happily ever after. The end...";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font slimeFont;
    sf::Font hoodFont;
    sf::Text line1Text;
    sf::Text lineTest[3];
    sf::Color textColor;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 550;
    int slimePosX = -200;
    int hoodedFigX = 1200;
    bool slimeTalk = true;
    bool hoodTalk = false;

    //for loading the font
    if(!slimeFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if(!hoodFont.loadFromFile("Ishmeria.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!forestSounds.openFromFile("openScene.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    forestSounds.play();
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
                        sc.playSelectSound();
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "...And the people lived happily ever after. The end...";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "Wow. I wish I could be human. They can laugh and live happily.";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "I am not sure what happiness even means...";
                                break;
                            case 3:
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "Did I hear this correctly? Do you wish to be human, small slime child?";
                                break;
                            case 4:
                                yPosLine = 550;
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "Whoa! Who are you? You look different from the other monsters!";
                                break;
                            case 5:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "I am a witch, and I can show you how to be human.";
                                break;
                            case 6:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "Become human?! You really mean it?!";
                                break;
                            case 7:
                                //lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "Yes child. You must collect three items hidden beside beasts.";
                                break;
                            case 8:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "B-beasts?? What kind of -";
                                break;
                            case 9:
                                lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "Collect these items, and meet me in Mount Serna in six days.";
                                break;
                            case 10:
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "Who was that guy?";
                                break;
                            case 11:
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "Doesn't matter I guess. Time to go get those items!";
                                break;

                        }
                    }
            }
        }

        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f) {
            if(slimePosX < 15) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 360);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if(slimeTalk && !hoodTalk) {
                        lineTest[0].setFont(slimeFont);
                        lineTest[0].setColor(sf::Color::Green);
                    }
                    if(hoodTalk && !slimeTalk) {
                        lineTest[0].setFont(hoodFont);
                        lineTest[0].setColor(sf::Color::White);
                    }
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, 550);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        lineTest[0].setString(line[0].substr(0, count));
                        count = 0;
                    }
                    if(slimeTalk && !hoodTalk) {
                        lineTest[0].setFont(slimeFont);
                        lineTest[1].setFont(slimeFont);
                        lineTest[0].setColor(sf::Color::Green);
                        lineTest[1].setColor(sf::Color::Green);

                    }
                    if(hoodTalk && !slimeTalk) {
                        lineTest[0].setFont(hoodFont);
                        lineTest[1].setFont(slimeFont);
                        lineTest[0].setColor(sf::Color::White);
                        lineTest[1].setColor(sf::Color::White);
                    }

                    lineTest[i].setCharacterSize(30);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }

        //enter hooded figure
        if(lineNum > 2 && lineNum < 9) {

            if(hoodedFigX > 960) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    hoodedFigure.setPosition(hoodedFigX, 150);
                    hoodedFigX--;
                    animateTime.restart();
                }
            }
        }

        if(lineNum > 9) {
            if(hoodedFigX < 1200) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    hoodedFigure.setPosition(hoodedFigX, 150);
                    hoodedFigX++;
                    animateTime.restart();
                }
            }
        }

        if(lineNum >11) {
            return;
        }

        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        hoodedFigure.draw(window);
        happySlime.draw(window);
        window.draw(textBox);
        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(370, 375);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene2(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(1);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("Plains_back.jpg", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "Alright I managed to get to the plains safely!";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text line1Text;
    sf::Text lineTest[3];
    sf::Color textColor;
    textColor.Green;
    sf::Music plainsMusic;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;
    int hoodedFigX = 1200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!plainsMusic.openFromFile("plainsMusic.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    plainsMusic.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        //lineTest[0].setString(' ');
                        //lineTest[1].setString(' ');
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Alright I managed to get to the plains safely!";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Now I need to find these herbs...";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Where could they be?";
                                break;
                            case 3:
                                line1 = " ";

                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 2) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    //lineTest[0].setStyle(sf::Text::Italic);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 2) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene3(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(1);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("Plains_back.jpg", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "Sweet! I found the herbs! That wasn't so bad after all";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text line1Text;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music plainsMusic;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;
    int hoodedFigX = 1200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!plainsMusic.openFromFile("plainsMusic.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    plainsMusic.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        //lineTest[0].setString(' ');
                        //lineTest[1].setString(' ');
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Sweet! I found the herbs! That wasn't so bad after all";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "The next item is animal skin. Where will I get that?";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "RAAWWRRRRRRR!";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Hey a tiger! How perfectly convinient! To the forest I go!";
                                break;
                            case 4:
                                line1 = " ";
                                break;

                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 3) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    if(lineNum == 2) {
                        lineTest[0].setStyle(sf::Text::Italic);
                        lineTest[0].setColor(sf::Color::Red);
                    }
                    else {
                        lineTest[0].setStyle(sf::Text::Regular);
                        lineTest[0].setColor(sf::Color::Green);
                    }
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::White);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 3) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene4(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(2);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "This forest is really creepy...";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("scenes4_5.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        //lineTest[0].setString(' ');
                        //lineTest[1].setString(' ');
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "This forest is really creepy...";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "The tiger over there looks like it could kill me too...";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "It'll be fine. I can find animal skin here.";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I'll just have to sneak around the tiger.";
                                break;
                            case 4:
                                line1 = " ";
                                break;

                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 3) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 3) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene5(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(2);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "I got the animal skin! I'm almost done!";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("scenes4_5.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        //lineTest[0].setString(' ');
                        //lineTest[1].setString(' ');
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I got the animal skin! I'm almost done!";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Gosh but the next item is a human bone.";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Where in the world will I get that?";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "...";
                                break;
                            case 4:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Wait! I remember a book I read once. A sunken ship in the ocean!";
                                break;
                            case 5:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I think the ship was called the Gigantic? Tit...anstick?";
                                break;
                            case 6:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "The name doesn't matter. I think I know where it is!";
                                break;
                            case 7:
                                line1 = " ";
                                break;


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 6) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 6) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene6(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(3);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("ocean_back.jpg", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "I never knew I could breathe underwater like this!";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("oceanScenes.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I never knew I could breathe underwater like this!";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "It's so pretty and awesome here! I should go swimming more often!";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "No time to swim though. Human bones...need to find that.";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = " ";


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 2) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 2) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene7(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(3);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("ocean_back.jpg", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "After all that no luck with human bones.";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("oceanScenes.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "After all that, no luck with human bones.";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Maybe that ship was just a myth.";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "There was a cave on shore that I could check though. I may as well try there";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = " ";


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 2) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 2) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene8(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(4);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("cave_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "This cave is really creepy...maybe I should leave.";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("caveMusic.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "This cave is really creepy...maybe I should leave.";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "No, no. I made it this far. I can do this.";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I want to be a human more than anything. I will find these bones.";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = " ";


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 2) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 2) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene9(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(4);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("cave_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "I can't believe I got all the items I need! I'm so excited!";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("caveMusic.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I can't believe I got all the items I need! I'm so excited!";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I actually get to become a human! I can feel joy like a human does!";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I won't be a monster any longer!";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "This is so exciting! Wow time to hurry and bring this to that guy!";
                                break;
                            case 4:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = " ";
                                break;


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 3) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 3) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}

void Scene::runScene10(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject hoodedFigure;
    AnimatedGameObject happySlime;
    Slime slimeBit(5);

    hoodedFigure.load("hoodFig2.png");
    happySlime.load("slime_normal_right.png");
    hoodedFigure.setScale(1.7f);
    happySlime.setScale(.9f);
    hoodedFigure.setCrop(0,0, 231, 300);
    hoodedFigure.setPosition(1300, 150); //950, 150
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("volcano_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "It's so...so hot";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font slimeFont;
    sf::Font hoodFont;
    sf::Text lineTest[3];
    sf::Music music;
    sf::Color textColor;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;
    int hoodedFigX = 1300;
    bool slimeTalk = true;
    bool hoodTalk = false;


    //for loading the font
    if(!slimeFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if(!hoodFont.loadFromFile("Ishmeria.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("scene10Music.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }

    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        //lineTest[0].setString(' ');
                        //lineTest[1].setString(' ');
                        switch(lineNum) {
                            case 0:
                                slimeTalk = true;
                                hoodTalk = false;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "It's so...so hot";
                                break;
                            case 1:
                                slimeTalk = true;
                                hoodTalk = false;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Why would he pick here of all places to meet? Does he live here?";
                                break;
                            case 2:
                                slimeTalk = true;
                                hoodTalk = false;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Where is he?";
                                break;
                            case 3:
                                slimeTalk = true;
                                hoodTalk = false;
                                //lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                line1 = "Oh! There you are!";
                                break;
                            case 4:
                                slimeTalk = false;
                                hoodTalk = true;
                                //lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                //yPosLine = 550;
                                line1 = "Do you have the items, slime?";
                                break;
                            case 5:
                                slimeTalk = true;
                                hoodTalk = false;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Yes!! I got them all!";
                                break;
                            case 6:
                                slimeTalk = false;
                                hoodTalk = true;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Give them to me, and I will make you human.";
                                break;
                            case 7:
                                slimeTalk = true;
                                hoodTalk = false;
                                //lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                line1 = "Alright here you go!";
                                break;
                            case 8:
                                slimeTalk = false;
                                hoodTalk = true;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "...";
                                break;
                            case 9:
                                slimeTalk = false;
                                hoodTalk = true;
                                lineTest[0].setString(' ');
                                //lineTest[1].setString(' ');
                                line1 = "...MWAHAHAHAHAHAHAH YOU FOOL";
                                break;
                            case 10:
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "I AM A HUMAN BEING AND YOU HAVE GIVEN ME ALL THE ITEMS I NEED TO LEAVE THIS WORLD";
                                break;
                            case 11:
                                slimeTalk = true;
                                hoodTalk = false;
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                yPosLine = 620;
                                line1 = "W-WHAT?!";
                                break;
                            case 12:
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "The world is cruel, young slime. I'm afraid I must let you go now";
                                break;
                            case 13:
                                slimeTalk = true;
                                hoodTalk = false;
                                line1 = "W-what is that monster you sent out?!";
                                break;
                            case 14:
                                slimeTalk = false;
                                hoodTalk = true;
                                line1 = "Just a pet for you to play with. Have fun, little slime";
                                break;
                            case 15:
                                line1 = " ";
                                break;

                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 3) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if(slimeTalk && !hoodTalk) {
                        lineTest[0].setFont(slimeFont);
                        lineTest[0].setColor(sf::Color::Green);
                    }
                    if(hoodTalk && !slimeTalk) {
                        lineTest[0].setFont(hoodFont);
                        if(lineNum >= 9 && lineNum <= 10) {
                            lineTest[0].setColor(sf::Color::Red);
                            lineTest[0].setStyle(sf::Text::Italic);
                        }
                        else {
                            lineTest[0].setColor(sf::Color::White);
                            lineTest[0].setStyle(sf::Text::Regular);
                        }
                    }
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    if(slimeTalk && !hoodTalk) {
                        lineTest[0].setFont(slimeFont);
                        lineTest[0].setColor(sf::Color::Green);
                    }
                    if(hoodTalk && !slimeTalk) {
                        lineTest[0].setFont(hoodFont);
                        if(lineNum >= 9 && lineNum <= 10) {
                            lineTest[0].setColor(sf::Color::Red);
                            lineTest[0].setStyle(sf::Text::Italic);
                        }
                        else {
                            lineTest[0].setColor(sf::Color::White);
                            lineTest[0].setStyle(sf::Text::Regular);
                        }
                    }

                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }

        //enter hooded figure
        if(lineNum > 2 && lineNum < 9) {

            if(hoodedFigX > 960) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    hoodedFigure.setPosition(hoodedFigX, 150);
                    hoodedFigX--;
                    animateTime.restart();
                }
            }
        }

        if(lineNum > 14) {
            if(hoodedFigX < 1200) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    hoodedFigure.setPosition(hoodedFigX, 150);
                    hoodedFigX++;
                    animateTime.restart();
                }
            }
        }
        if(lineNum > 14) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }




        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        hoodedFigure.draw(window);
        happySlime.draw(window);
        window.draw(textBox);
        //sc.draw(window);
        //window.draw(line1Text);
        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
        //sc.renderScene(window, sc, backgroundIm, textBox);
        //std::cout << "CLock time" << clk.getElapsedTime().asSeconds() << std::endl;
    }
}

void Scene::runScene11(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create the gameOver screen
    AnimatedGameObject happySlime;
    Slime slimeBit(5);

    happySlime.load("slime_normal_right.png");
    happySlime.setScale(.9f);
    happySlime.setPosition(-250, 0); //15, 360


    Scene sc(screenX, screenY);
    // play gameover sound
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("volcano_back.png", sf::Vector2f(screenX, screenY));
    sf::RectangleShape textBox(sf::Vector2f(screenX, (screenY/4)));
    textBox.setPosition(sf::Vector2f(0, 620));
    textBox.setFillColor(sf::Color::Black);
    // fade in
    //sc.fadeIn(window, sc, backgroundIm);
    // loop to check for key presses
    std::string line1 = "*huff* I *huff*";
    sf::Clock clkText;
    sf::Clock sceneTime;
    sf::Clock animateTime;
    sf::Font sceneFont;
    sf::Text lineTest[3];
    sf::Color textColor;
    sf::Music music;
    textColor.Green;

    //line vector and positions for animation
    std::vector<std::string> line;
    int yPosLine = 620;
    int slimePosX = -200;



    //for loading the font
    if(!sceneFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if (!music.openFromFile("lastSceneMusic.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    int count = 1;
    int i =0;
    int lineNum = 0;

    //for the enter key
    music.play();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    sc.playSelectSound();
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        lineNum++;
                        count = 0;
                        switch(lineNum) {
                            case 0:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "*huff* I *huff*";
                                break;
                            case 1:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "I just wanted to be human...";
                                break;
                            case 2:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "But...after meeting one...I just wish I wanted to stay myself.";
                                break;
                            case 3:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = "Goodbye cruel world...";
                                break;
                            case 4:
                                lineTest[0].setString(' ');
                                lineTest[1].setString(' ');
                                line1 = " ";
                                break;


                        }
                    }
            }
        }



        //sliding the slime character into frame to speak
        if(sceneTime.getElapsedTime().asSeconds() > 2.0f && lineNum < 3) {
            if(slimePosX < 25) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX++;
                    animateTime.restart();
                }
            }
        }

        if(line1.length() <= 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    lineTest[0].setFont(sceneFont);
                    lineTest[0].setColor(sf::Color::Green);
                    lineTest[0].setCharacterSize(30);
                    lineTest[0].setPosition(15, yPosLine);
                    lineTest[0].setString(line1.substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }
        line = sc.createStrings(line1);

        if(line1.length() > 70) {
            if (sceneTime.getElapsedTime().asSeconds() > 3.0f) {
                if (clkText.getElapsedTime().asSeconds() > .07f) {
                    if (count == 71) {
                        yPosLine = yPosLine + 50;
                        i = 1;
                        lineTest[i - 1].setString(line[i - 1].substr(0, count));
                        count = 0;
                    }
                    //std::cout << line1.substr(0,count) << std::endl;
                    lineTest[i].setFont(sceneFont);
                    lineTest[i].setColor(sf::Color::Green);
                    lineTest[i].setCharacterSize(30);
                    //lineTest[i].setStyle(sf::Text::Italic);
                    lineTest[i].setPosition(15, yPosLine);
                    lineTest[i].setString(line[i].substr(0, count));
                    clkText.restart();
                    count++;
                }
            }
        }


        if(lineNum > 3) {
            if(slimePosX > -300) {
                if(animateTime.getElapsedTime().asSeconds() > .003f) {
                    happySlime.setPosition(slimePosX, 435);
                    slimePosX--;
                    animateTime.restart();
                }
            }
            if(slimePosX <= -300) {
                return;
            }
        }



        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        happySlime.draw(window);
        window.draw(textBox);

        window.draw(lineTest[0]);
        window.draw(lineTest[1]);
        slimeBit.setPosition(0, 500);
        slimeBit.draw(window);
        slimeBit.update(32, 32*9);
        window.display();
    }
}
