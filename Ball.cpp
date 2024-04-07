#include "Ball.h"
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

void Ball::draw(Graphics^ gfx)
{
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(_color));

    int centerx = static_cast<int>(_x - _size / 2);
    int centery = static_cast<int>(_y - _size / 2);
    int width = static_cast<int>(_size);
    int height = static_cast<int>(_size);
    gfx->FillEllipse(brush, centerx, centery, width, height);
}