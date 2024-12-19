#include <math.h>
#include "simulator.h"

const double PI = atan(1) * 4;

Simulator::Simulator(Robot& robot) : _robot(robot) {
    _window = new sf::RenderWindow(sf::VideoMode(FIELD_SIZE, FIELD_SIZE), "Robot Simulator");
    _window->setFramerateLimit(FPS);
}

Simulator::~Simulator() {
    delete _window;
}

void Simulator::run() {
    sf::Clock clock;

    while(_window->isOpen()) {
        // Handle events
        sf::Event event;
        while(_window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) _window->close();
        }

        float dt = clock.restart().asSeconds();

        // Render
        _window->clear();
        renderField();
        renderRobot();
        _window->display();
    }
}

void Simulator::renderField() {
    for(int r = 0; r < 6; r++) {
        for(int c = 0; c < 6; c++) {
            sf::RectangleShape square(sf::Vector2f(FIELD_SIZE / 6, FIELD_SIZE / 6));
            square.setPosition(c * FIELD_SIZE / 6, r * FIELD_SIZE / 6);

            if((r + c) % 2 == 0) {
                square.setFillColor(sf::Color(211, 211, 211));
            } else {
                square.setFillColor(sf::Color(181, 181, 181));
            }

            _window->draw(square);
        }
    }
}

void Simulator::renderRobot() {
    sf::RectangleShape robotShape(sf::Vector2f(ROBOT_WIDTH, ROBOT_LENGTH));
    robotShape.setOrigin(ROBOT_WIDTH / 2, ROBOT_LENGTH / 2);
    robotShape.setPosition(_robot.getX(), _robot.getY());
    robotShape.setRotation(_robot.getTheta() * 180.0f / PI);
    robotShape.setFillColor(sf::Color::Blue);

    _window->draw(robotShape);
}