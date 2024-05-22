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
    int countOf(const type_info* type);
    void place(PopObject* popObject);
    void destroyAll();
    PopObject* nearest(PopObject * popObject);
    PopObject* nearestFriend(PopObject* popObject);
    PopObject* nearestAlien(PopObject* popObject);
    void removeExplosions();
};

extern Manager* manager;