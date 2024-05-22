#pragma once
#include "Mover.h"
class Hunter :
    public Mover
{
private:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();
    void doCommand(char command);
};

