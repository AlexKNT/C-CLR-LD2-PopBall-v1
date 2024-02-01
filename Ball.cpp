#include "Ball.h"
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

void Ball::draw(Graphics^ gfx) {
    SolidBrush^ brush = gcnew SolidBrush(Color(_color));
    int radius = _size / 2;
    gfx->FillEllipse(brush, _x - radius, _y - radius, _size, _size);
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
    _color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256); // Random color

    // Set initial position to the center of the frame
    _x = _frameWidth / 2;
    _y = _frameHeight / 2;
}