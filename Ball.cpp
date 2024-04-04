#include "Ball.h"
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

void Ball::draw(Graphics^ g) {
    g->FillEllipse(Brushes::White, x, y, width, height);
})