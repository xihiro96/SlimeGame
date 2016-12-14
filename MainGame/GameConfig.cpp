//
// Created by Randy Deng on 12/13/16.
//

#include "GameConfig.h"

// constructor/destructor
GameConfig::GameConfig() {
}
GameConfig::~GameConfig() {
}

// config functions
// load config
void GameConfig::loadConfig(Config &config) {
    std::ifstream fin("config.txt");
    std::string line;
    if (fin.good()) {
        while (getline(fin, line)) {
            std::istringstream sin(line.substr(line.find("=") + 1));
            if (line.find("level") != -1)
                sin >> config.level;
            else if (line.find("sceneNum") != -1)
                sin >> config.sceneNum;
            else if (line.find("highScore") != -1)
                sin >> config.highScore;
        }
    } else {
        std::cout << "Error reading config file" << std::endl;
    }
    fin.close();
}
// write config
void GameConfig::writeConfig(Config &config) {
    // delete content
    std::ofstream myfile;
    myfile.open("/SlimeGame/config.txt", std::ofstream::out | std::ofstream::trunc);
    if (myfile.good()) {
        // write to file
        myfile << "//Configuration and Data for Slime Adventures\n";
        myfile << "//Do not change values\n";
        myfile << "level = " << config.level << "\n";
        myfile << "sceneNum = " << config.sceneNum << "\n";
        myfile << "highScore = " << config.highScore << "\n";
        // close file
        myfile.close();
    } else {
        std::cout << "Error reading config file" << std::endl;
    }
}

// resets level, cutscene, and other parameters
void GameConfig::gameReset(Config &config) {
    config.level = 1;
    config.sceneNum = 1;
}
// reset all score data
void GameConfig::scoreReset(Config &config) {
    config.highScore = 99999;
}