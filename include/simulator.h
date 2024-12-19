#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <SFML/Graphics.hpp>
#include "robot.h"

class Simulator {

public:
    Simulator();
    ~Simulator();

    void run();

private:
    // Simulation parameters
    const float FIELD_WIDTH = 12.0f * 12.0f;  // 12 feet in inches
    
    // SFML components
    sf::RenderWindow* _window;
    Robot* _robot;
    
    void renderField();
    void renderRobot();
    void handleInput(float dt);
};

#endif // SIMULATOR_H