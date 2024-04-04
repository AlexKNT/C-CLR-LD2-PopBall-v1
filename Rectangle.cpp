#include "Rectangle.h"
#include "Mover.h"
#include "Rotator.h"

void Rectangle::draw(Graphics^ gfx)
{
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(_color));
    // Clean up the brush
    delete brush;
}
