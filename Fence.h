#pragma once
#include "Mover.h"
class Fence :
    public Mover
{
public:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();

};

