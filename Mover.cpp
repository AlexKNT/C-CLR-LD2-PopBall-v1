#include "Mover.h"
#include <cstdlib>
#include <ctime>

Mover::Mover(int frameWidth, int frameHeight, int x, int y) : _frameWidth(frameWidth), _frameHeight(frameHeight), _x(x), _y(y)
{
    _x = static_cast<float>(x);
    _y = static_cast<float>(y);

    _size = rand() % 20 + 10; 
    _color = rand() % 256;     

    do
    {
        _dX = static_cast<float>(rand() % 21 - 10); // Random value between -10 and 10
        _dY = static_cast<float>(rand() % 21 - 10); // Random value between -10 and 10
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
    _x = static_cast<float>(x);
    _y = static_cast<float>(y);

    // Check if the new position is within acceptable limits
    int radius = getRadius();
    if (_x - radius < 0)
        _x = static_cast<float>(radius);
    if (_x + radius > _frameWidth)
        _x = static_cast<float>(_frameWidth - radius);
    if (_y - radius < 0)
        _y = static_cast<float>(radius);
    if (_y + radius > _frameHeight)
        _y = static_cast<float>(_frameHeight - radius);
}

int Mover::getRadius()
{
    return _size / 2;

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

bool Mover::interactable() {
    return true;
}

void Mover::followTo(int x, int y)
{
    // Calculate the vector from the current position to the target position
	float dx = x - _x;
	float dy = y - _y;

	// Calculate the length of the vector
	float length = sqrt(dx * dx + dy * dy);

	// Normalize the vector
	dx /= length;
	dy /= length;

	// Set the new speed
	setSpeed(dx, dy);
}

void Mover::followAway(int x, int y)
{
	// Calculate the vector from the current position to the target position
	float dx = _x - x;
	float dy = _y - y;

	// Calculate the length of the vector
	float length = sqrt(dx * dx + dy * dy);

	// Normalize the vector
	dx /= length;
	dy /= length;

	// Set the new speed
	setSpeed(dx, dy);
}
