#include "Triangle.h"
#include "Mover.h"
#include "Rotator.h"
#include <cmath>
using namespace System::Drawing;

void Triangle::draw(Graphics^ gfx)
{
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(0xFF00FF00));

    // Define triangle points relative to its center
    array<PointF>^ points = gcnew array<PointF>(3);
    float halfWidth = _size / 2.0f;
    float halfHeight = (_size / 2.0f) * std::sqrt(3) / 2.0f; // Height of an equilateral triangle
    points[0] = PointF(_x, _y - halfHeight); // Top vertex
    points[1] = PointF(_x - halfWidth, _y + halfHeight); // Bottom left vertex
    points[2] = PointF(_x + halfWidth, _y + halfHeight); // Bottom right vertex

    // Rotate each point around the triangle's center
    for (int i = 0; i < 3; i++) {
        float dx = points[i].X - _x;
        float dy = points[i].Y - _y;
        float distance = std::sqrt(dx * dx + dy * dy);
        float angle = std::atan2(dy, dx) + Rotator::getDAlpha(); // Rotating using Rotator's angle
        points[i].X = _x + distance * std::cos(angle);
        points[i].Y = _y + distance * std::sin(angle);
    }

    gfx->FillPolygon(brush, points);

}