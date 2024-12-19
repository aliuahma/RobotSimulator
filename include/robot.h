#ifndef ROBOT_H
#define ROBOT_H

class Robot {
public:
    Robot(float x, float y, float theta) : _x(x), _y(y), _theta(theta) {};
    ~Robot() = default;

    float getX() const { return _x; }
    float getY() const { return _y; }
    float getTheta() const { return _theta; }
    float getWidth() const { return WIDTH; }
    float getLength() const { return LENGTH;}

private:
    // Robot state
    float _x = 0.0f;                    // inches
    float _y = 0.0f;                    // inches
    float _theta = 0.0f;                // degrees

    // Physical properties
    const float WIDTH = 15.0f;         // inches
    const float LENGTH = 15.0f;        // inches    
    const float WEIGHT = 14.0f;        // pounds

    // Movement properties
    const float LINEAR_SPEED = 0.0f;   // inches per second
    const float ANGULAR_SPEED = 0.0f;  // degrees per second
};

#endif // ROBOT_H