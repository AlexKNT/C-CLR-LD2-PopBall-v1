#pragma once

using namespace System::Drawing;

class PopObject
{
public:
    virtual float getX();
    virtual float getY();
    virtual void setPos(int x, int y);
    virtual int getSize() const;
    virtual void draw(Graphics^ graphics);
    virtual float getdX();
    virtual float getdY();
    virtual void setSpeed(float dX, float dY);
    virtual void move();
    virtual void interact(PopObject* obj);
};