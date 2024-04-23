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
    bool isMarkedForDeletion() const;
    void markForDeletion();

private:
    float _maxLifetime; // Maximum lifetime of the explosion
    float _lifetime;    // Current remaining lifetime of the explosion
    bool _markedForDeletion; // Flag indicating if the explosion is marked for deletion
};

