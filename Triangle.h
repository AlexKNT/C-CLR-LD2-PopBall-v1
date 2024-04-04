#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Triangle : public Rotator
{
public:
    Triangle(int frameWidth, int frameHeight, int x, int y);
    void draw(Graphics^ gfx);
};

