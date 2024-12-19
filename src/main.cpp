#include <SFML/Graphics.hpp>
#include "robot.h"
#include "simulator.h"

int main() {
    Robot robot(300.0f, 300.0f, 0.0f);
    Simulator simulator(robot);
    simulator.run();
    return 0;
}