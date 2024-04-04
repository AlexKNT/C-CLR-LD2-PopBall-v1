#pragma once
#include "PopObject.h"
class Mover : public PopObject
{
protected:
    float _x = 0;
    float _y = 0;
    float _dX = 0;
    float _dY = 0;
    int _color = 0x78FF0000;
    int _size = 0;
    int _frameWidth = 0;
    int _frameHeight = 0;
public:
    Mover(int frameWidth, int frameHeight, int x, int y); // Constructor with additional parameters
    void setPos(int x, int y) override;
    int getSize();
    float getX();
    float getY();
    void interact(PopObject* obj);
    float getdX();
    float getdY();
    void setSpeed(float dX, float dY);
    void move();
};

