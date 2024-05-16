#pragma once
#include "PopObject.h"
class Mover : public PopObject
{
protected:
    float _x = 0;
    float _y = 0;
    float _dX = 0;
    float _dY = 0;
    int _color = 0xFFFF0000;
    int _size = 0;
    int _frameWidth = 0;
    int _frameHeight = 0;
public:
    Mover(int frameWidth, int frameHeight, int x, int y);
    void setPos(int x, int y) override;
    int getSize() override;
    float getX() override;
    float getY() override;
    void interact(PopObject* obj) override;
    float getdX() override;
    float getdY() override;
    void setSpeed(float dX, float dY) override;
    void move() override;
    int getRadius();
    void onWallCollision() override;
    bool interactable();
    void followTo(int x, int y); // izmainīt kustības virzienu pie norādītā punkta
    void followAway(int x, int y); // izmainīt kustības virzienu pretvirzienā no norādītā punkta
};

