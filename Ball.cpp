#include "Ball.h"
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

void Ball::draw(Graphics^ gfx)
{
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(_color));

    int centerx = _x - _size / 2;
    int centerx = _x - _size / 2;
    int centery = _y - _size / 2;
    int width = _size;
    int height = _size;
    gfx->FillEllipse(brush, centerx, centery, width, height);
    // Clean up the brush
    delete brush;
}