#pragma once
#include "Mover.h"
class House :
    public Mover
{
private:
public:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();
    House(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight, x, y) {}
};

