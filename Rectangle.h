#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Rectangle : public Rotator
{
public:
    Rectangle(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth, frameHeight, x, y) {}
    void draw(Graphics^ gfx);
};

