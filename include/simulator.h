#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <SFML/Graphics.hpp>
#include "robot.h"

class Simulator {

public:
    Simulator(Robot& robot);
    ~Simulator();

    void run();

private:
    // Simulation parameters
    const int PIXEL_SCALE = 100;  // pixels per foot
    const int FIELD_SIZE = 12 * PIXEL_SCALE;  // feet * PIXEL_SCALE
    const int ROBOT_WIDTH = 15 * PIXEL_SCALE / 12;  // inches * PIXEL_SCALE / 12
    const int ROBOT_LENGTH = 18 * PIXEL_SCALE / 12;  // inches * PIXEL_SCALE / 12
    const int FPS = 120;  // frames per second
    
    // SFML components
    sf::RenderWindow* _window;
    Robot _robot;
    
    void renderField();
    void renderRobot();
    void handleInput(float dt);
};

#endif // SIMULATOR_H