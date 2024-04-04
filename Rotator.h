#pragma once
#include "Mover.h"
class Rotator : public Mover
{
private:
    float _alpha = 0;
    float _dAlpha = 0;
public:
    Rotator(int frameWidth, int frameHeight, int x, int y, float alpha, float dAlpha)
        : Mover(frameWidth, frameHeight, x, y), _alpha(alpha), _dAlpha(dAlpha) {}
    void move();
};

