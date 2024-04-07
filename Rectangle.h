#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Rectangle_ : public Rotator
{
public:
    Rectangle_(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth, frameHeight, x, y) {}
    void draw(Graphics^ gfx);
};

