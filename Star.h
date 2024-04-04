#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Star : public Rotator
{
public:
    Star(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth, frameHeight, x, y) {}
    void draw(Graphics^ gfx);
};

