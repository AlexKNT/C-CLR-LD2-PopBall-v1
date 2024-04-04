#pragma once
#include "Mover.h"
class Rotator : public Mover
{
private:
    float _alpha = 0;
    float _dAlpha = 0;
public:
    Rotator(int frameWidth, int frameHeight, int x, int y);
    void move();
};

