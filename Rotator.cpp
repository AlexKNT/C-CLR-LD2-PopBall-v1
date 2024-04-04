#include "Rotator.h"

void Rotator::move() {
    _alpha += _dAlpha;
    Mover::move();
}
