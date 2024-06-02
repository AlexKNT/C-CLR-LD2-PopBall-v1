#pragma once
#include "Mover.h"
class House :
    public Mover
{
public:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();
};

