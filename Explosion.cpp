#include "Explosion.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

constexpr float FADE_OUT_RATE = 0.002f;

void Explosion::move()
{
    // Decrease the remaining lifetime of the explosion
    _lifetime -= FADE_OUT_RATE;

    // If the lifetime is less than or equal to zero, mark the explosion for deletion
    if (_lifetime <= 0.0f) {
        markForDeletion();
    }
}


void Explosion::draw(Graphics^ gfx)
{
    // Calculate the alpha value based on the remaining lifetime of the explosion
    int alpha = static_cast<int>(std::max(0.0f, static_cast<float>(255) * _lifetime / _maxLifetime));

    // Create a semi-transparent color for the explosion
    Color explosionColor = Color::FromArgb(alpha, Color::Red);

    // Draw the explosion as a simple circle with a fading color
    SolidBrush^ brush = gcnew SolidBrush(explosionColor);

    // Adjust the size of the explosion according to its remaining lifetime
    int explosionSize = static_cast<int>(getSize() * _lifetime / _maxLifetime);

    // Calculate the position for drawing the explosion
    int centerx = static_cast<int>(getX() - explosionSize / 2);
    int centery = static_cast<int>(getY() - explosionSize / 2);

    // Draw the explosion
    gfx->FillEllipse(brush, centerx, centery, explosionSize, explosionSize);
}

bool Explosion::isMarkedForDeletion() const
{
    return _markedForDeletion;
}

void Explosion::markForDeletion()
{
    _markedForDeletion = true;
}

bool Explosion::interactable(PopObject* popObject)
{
	return false;
}
