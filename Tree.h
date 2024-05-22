#pragma once
#include "Mover.h"
class Tree :
    public Mover
{
public:
    void draw(Graphics^ gfx) override;
    void move() override;
    bool interactable();
    Tree(int x, int y, int width, int height, int speed, int direction);
    
};

