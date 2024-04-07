#pragma once
#include "PopObject.h"

using namespace System::Drawing;

#define MAX_OBJECTS 1000

class Manager
{
private:
    PopObject* _popObjects[MAX_OBJECTS];
    int _frameWidth, _frameHeight;
public:
    Manager(int frameWidth = 600, int frameHeight = 400);
    ~Manager();
    void add(PopObject* popObject);
    void drawFrame(Graphics^ graphics);
    void move();
    bool remove(PopObject* popObject);
};

extern Manager* manager;