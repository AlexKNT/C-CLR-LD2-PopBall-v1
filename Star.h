#pragma once
#include "Rotator.h"
using namespace System::Drawing;
class Star : public Rotator
{
public:
    Star(int frameWidth, int frameHeight, int x, int y);
    void draw(Graphics^ gfx);
};

