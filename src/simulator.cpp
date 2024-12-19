#include "simulator.h"

Simulator::Simulator() {
    _window = new sf::RenderWindow(sf::VideoMode(1200, 1200), "Robot Simulator");
    _window->setFramerateLimit(120);
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
        _window->display();
    }
}

void Simulator::renderField() {
    for(int r = 0; r < 6; r++) {
        for(int c = 0; c < 6; c++) {
            sf::RectangleShape square(sf::Vector2f(200, 200));
            square.setPosition(c * 200, r * 200);

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
    sf::RectangleShape robotShape(sf::Vector2f(_robot->getWidth(), _robot->getLength()));
}