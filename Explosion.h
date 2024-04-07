#pragma once
#include "Mover.h"
#include "PopObject.h"
using namespace System::Drawing;
class Explosion : public Mover
{
public:
    Explosion(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight, x, y) {};
    void move();
    void draw(Graphics^ gfx);
    bool interactable(PopObject* popObject);
};

