//
// Created by Randy Deng on 12/13/16.
//

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Config {
    int level;
    int sceneNum;
    double highScore;
};

class GameConfig {
public :
    // constructor/destructor
    GameConfig();
    ~GameConfig();
    // config functions
    // load config
    static void loadConfig(Config&);
    // write to config
    static void writeConfig(Config&);
    // resets level, cutscene, and other parameters
    static void gameReset(Config&);
    // reset all score data
    static void scoreReset(Config&);
};