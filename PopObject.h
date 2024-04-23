#pragma once

using namespace System::Drawing;

class PopObject abstract
{
public:
    virtual ~PopObject() {}
    virtual float getX();
    virtual float getY();
    virtual void setPos(int x, int y) = 0;
    virtual int getSize();
    virtual void draw(Graphics^ graphics);
    virtual float getdX();
    virtual float getdY();
    virtual void setSpeed(float dX, float dY);
    virtual void move();
    virtual void onWallCollision();
    virtual void interact(PopObject* obj);
    virtual bool interactable(PopObject* obj);
};
