#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Triangle : public Rotator
{
public:
    Triangle(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth, frameHeight, x, y) {}
    void draw(Graphics^ gfx);
};

