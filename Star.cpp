#include "Star.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace System::Drawing;

void Star::draw(Graphics^ gfx) {
    SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(0xFFFF2040));

    PointF center = PointF(_x, _y);
    float radius = _size / 2;
    array<PointF>^ points = gcnew array<PointF>(10);


    for (int i = 0; i < 10; i++) {
        // Calculate angle in radians, adding an offset of -90 degrees (-PI/2 radians) to rotate the star
        float angle = ((float)i / 10 * 2 * M_PI) - getDAlpha();

        // Alternate between the outer and inner radius to create the star effect
        float r = i % 2 == 0 ? radius : radius / 2;

        points[i] = PointF(center.X + r * std::cos(angle), center.Y + r * std::sin(angle));
    }

    gfx->FillPolygon(brush, points);
}
