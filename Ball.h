#pragma once
#include "Mover.h"
using namespace System::Drawing;

class Ball : public Mover
{

public:
    Ball(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight, x, y) {}
    void draw(Graphics^ gfx);
};