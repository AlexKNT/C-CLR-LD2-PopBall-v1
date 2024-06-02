#include "House.h"
#include "Pictures.h"

void House::draw(Graphics^ gfx)
{
    gfx->DrawImage(Pictures::house, _x, _y);
}

void House::move()
{
    //
}

bool House::interactable()
{
    return true;
}
