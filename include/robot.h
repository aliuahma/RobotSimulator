#ifndef ROBOT_H
#define ROBOT_H

class Robot {
public:
    Robot(float x, float y, float theta);
    ~Robot();

    float getX() const { return x; }
    float getY() const { return y; }
    float getTheta() const { return theta; }
    float getWidth() const { return WIDTH; }
    float getLength() const { return LENGTH;}


private:
    // Physical properties
    const float WIDTH = 15.0f;         // inches
    const float LENGTH = 15.0f;        // inches    
    const float WEIGHT = 14.0f;        // pounds

    // Robot state
    float x = 0.0f;                    // inches
    float y = 0.0f;                    // inches
    float theta = 0.0f;                // degrees

    // Movement properties
    const float LINEAR_SPEED = 0.0f;   // inches per second
    const float ANGULAR_SPEED = 0.0f;  // degrees per second
};

#endif // ROBOT_H