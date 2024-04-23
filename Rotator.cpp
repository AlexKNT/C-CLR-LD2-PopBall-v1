#include "Rotator.h"

void Rotator::move() {
    _alpha += _dAlpha;
    Mover::move();
}

float Rotator::getAlpha() {
    return _alpha;
}

void Rotator::setAlpha(float alpha) {
    _alpha = alpha;
}

float Rotator::getDAlpha() {
    return _dAlpha;
}

void Rotator::setDAlpha(float dAlpha) {
    _dAlpha = dAlpha;
}

void Rotator::onWallCollision()
{
	_dAlpha = -_dAlpha;
}
