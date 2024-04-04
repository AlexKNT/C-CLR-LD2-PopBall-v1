#pragma once

using namespace System::Drawing;

class PopObject
{
public:
    virtual float getX() const;
    virtual float getY() const;
    virtual void setPos(int x, int y);
    virtual int getSize() const;
    virtual void draw(Graphics^ graphics) const;
    virtual float getdX() const;
    virtual float getdY() const;
    virtual void setSpeed(float dX, float dY);
    virtual void move() const;
    virtual void interact(PopObject* obj);
};