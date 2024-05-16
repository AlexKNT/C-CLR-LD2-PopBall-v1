#include "Rectangle.h"
#include "Mover.h"
#include "Rotator.h"
#include <cmath>
using namespace System::Drawing;

void Rectangle_::draw(Graphics^ gfx) {
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(0xFF0000FF));

    int left = static_cast<int>(_x - _size / 2);
    int top = static_cast<int>(_y - _size / 2);
    int width = static_cast<int>(_size);
    int height = static_cast<int>(_size);

    // Calculate the rectangle's corners
    array<PointF>^ corners = gcnew array<PointF>(4);
    corners[0] = PointF(left, top);
    corners[1] = PointF(left + width, top);
    corners[2] = PointF(left + width, top + height);
    corners[3] = PointF(left, top + height);

    // Rotate each corner around the rectangle's center
    for (int i = 0; i < 4; i++) {
        float dx = corners[i].X - _x;
        float dy = corners[i].Y - _y;
        float distance = std::sqrt(dx * dx + dy * dy);
        float angle = std::atan2(dy, dx) + Rotator::getDAlpha();
        corners[i].X = _x + distance * std::cos(angle);
        corners[i].Y = _y + distance * std::sin(angle);
    }

    gfx->FillRectangle(brush, left, top, width, height);
}
