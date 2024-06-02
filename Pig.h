#pragma once
#include "Animal.h"
class Pig :
    public Animal
{
public:

    void draw(Graphics^ gfx);

    void move();

    bool interactable();

    void update();

};

