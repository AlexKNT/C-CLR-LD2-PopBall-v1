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

Ball* ball;