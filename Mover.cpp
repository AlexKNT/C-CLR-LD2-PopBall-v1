#include "Mover.h"
#include <cstdlib>
#include <ctime>

Mover::Mover(int frameWidth, int frameHeight, int x, int y) : _frameWidth(frameWidth), _frameHeight(frameHeight), _x(x), _y(y)
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set random size and color
    _size = rand() % 20 + 10; // Random size between 10 and 30
    _color = rand() % 256;     // Random color

    // Set random initial speeds
    do
    {
        _dX = (rand() % 21 - 10); // Random value between -10 and 10
        _dY = (rand() % 21 - 10); // Random value between -10 and 10
    } while (_dX == 0 && _dY == 0); // Ensure that both velocities are non-zero

    // Ensure that both velocities are non-zero at the same time
    if (_dX == 0)
        _dX = 1;
    if (_dY == 0)
        _dY = 1;
}


void Mover::setPos(int x, int y)
{
    // Set new position
    _x = x;
    _y = y;

    // Check if the new position is within acceptable limits
    int radius = _size / 2;
    if (_x - radius < 0)
        _x = radius;
    if (_x + radius > _frameWidth)
        _x = _frameWidth - radius;
    if (_y - radius < 0)
        _y = radius;
    if (_y + radius > _frameHeight)
        _y = _frameHeight - radius;
}

int Mover::getSize()
{
    return _size;
}

float Mover::getX()
{
    return _x;
}

float Mover::getY()
{
    return _y;
}

void Mover::interact(PopObject* obj)
{
    // Reaction to collision
    // In this simplified approach, simply reverse the direction after collision
    _dX = -_dX;
    _dY = -_dY;
}

float Mover::getdX()
{
    return _dX;
}

float Mover::getdY()
{
    return _dY;
}

void Mover::setSpeed(float dX, float dY)
{
    _dX = dX;
    _dY = dY;

    // Ensure that both velocities are non-zero at the same time
    if (_dX == 0 && _dY == 0)
    {
        _dX = 1;
    }
}

void Mover::move()
{
    // Update coordinates based on current velocity
    _x += _dX;
    _y += _dY;

    // Check if the ball is out of frame
    int radius = _size / 2;
    if (_x - radius < 0 || _x + radius > _frameWidth)
    {
        // Ball hits left or right wall, change horizontal velocity
        _dX = -_dX;
    }
    if (_y - radius < 0 || _y + radius > _frameHeight)
    {
        // Ball hits top or bottom wall, change vertical velocity
        _dY = -_dY;
    }
}