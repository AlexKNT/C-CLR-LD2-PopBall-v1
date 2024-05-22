#pragma once
#include "Mover.h"
class Bullet :
    public Mover
{
private:
    int ricochets_ = 0;
public:
    void draw(Graphics^ gfx) override;
    void move() override;
    void interact(PopObject* obj) override;
    Bullet(int frameWidth, int frameHeight, int x, int y);
};

