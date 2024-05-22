#pragma once
#include "Mover.h"
class Animal :
    public Mover
{
private:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();

    
};

