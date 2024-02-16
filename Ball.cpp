#include "Ball.h"
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

void Ball::draw(Graphics^ gfx) {
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(_color));

    int centerx = _x - _size / 2; 
    int centery = _y - _size / 2;
    int width = _size;
    int height = _size;

    gfx->FillEllipse(brush, centerx, centery, width, height);

    // Clean up the brush
    delete brush;
}

void Ball::setPos(int x, int y) {
    // Set new position
    _x = x;
    _y = y;

    // Check if the new position is within acceptable limits
    int radius = _size / 2;
    if (_x - radius < 0) _x = radius;
    if (_x + radius > _frameWidth) _x = _frameWidth - radius;
    if (_y - radius < 0) _y = radius;
    if (_y + radius > _frameHeight) _y = _frameHeight - radius;
}

Ball::Ball(int frameWidth, int frameHeight) {
    _frameWidth = frameWidth;
    _frameHeight = frameHeight;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set random size and color
    _size = rand() % 20 + 10; // Random size between 10 and 30
    _color = rand() % 256; // Random color

    // Set initial position to the center of the frame
    _x = _frameWidth / 2;
    _y = _frameHeight / 2;
}

int Ball::setColor(int color) {
    _color = color;
    return _color;
}

float Ball::getdX() {
    return _dX;
}

float Ball::getdY() {
    return _dY;
}

/*
To provide the ball with the possibility of movement, two data members must be added to it, which will store the speed of the ball - _dX, _dY. In the constructor, new data members must be given initial values that can be chosen randomly from the range -10..10, checking that both velocities are non-zero at the same time. In order to ensure the possibility of working with the speed of form methods, it is necessary to add Ball methods to the class through which the data members _dX and _dY could be read and changed. To describe movement, the ball class must write a move method that describes one step of movement. During the execution of the step you need:
1. change the coordinates of the ball according to the speed – increase the coordinate _x by the horizontal speed _dX, and the coordinate _y – by the vertical speed _dY,
2. if the ball will then be out of frame, change the speed in such a way that the ball bounces off the wall.
*/

/*
A movement option is described by its speed. In our case, the speed represents how the ball's coordinates change by one step of movement (i.e. the unit of speed is pixels/step). Velocity is a vector and can be stored as two numbers: dX – projection of velocity on the X axis (horizontal velocity) and dY – projection of velocity on the Y axis (vertical velocity). The horizontal speed shows how many pixels the coordinate X changes for one movement step, the vertical speed shows how many pixels the coordinate Y changes for one movement step. Sometimes it is better to represent the speed with the Speed module, which shows the magnitude of the speed, and with the angle Angle, which determines the direction of movement.
Spped = sqrt(dX^2 + dY^2)
Angle = atan2(dY/dX)
dX = Speed * cos(Angle)
dY = Speed * sin(Angle)
*/

void Ball::setSpeed(float dX, float dY) {
    _dX = dX;
    _dY = dY;

    // Ensure that both velocities are non-zero at the same time
    if (_dX == 0 && _dY == 0) {
        _dX = 1;
    }
}

void Ball::move() {
    _x += _dX;
    _y += _dY;

    // Check if the ball is out of frame
    int radius = _size / 2;
    if (_x - radius < 0 || _x + radius > _frameWidth) {
        // Ball hits the left or right wall, reverse horizontal speed
        _dX = -_dX;
    }
    if (_y - radius < 0 || _y + radius > _frameHeight) {
        // Ball hits the top or bottom wall, reverse vertical speed
        _dY = -_dY;
    }
}

Ball* ball;