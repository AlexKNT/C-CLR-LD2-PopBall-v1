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
    // atrast kolekcijā vistuvāko figūru pie uzdotas figūras un atgriež tā adresi
    PopObject* nearest(PopObject * popObject);
    // atrast kolekcijā vistuvāko figūru ar to pašu tipu kā uzdotai figūrai un atgriež tā adresi
    PopObject* nearestFriend(PopObject* popObject);
    // atrast kolekcijā vistuvāko figūru ar tipu, kas nesakrīt ar uzdotas figūras tipu, un atgriež tā adresi
    PopObject* nearestAlien(PopObject* popObject);
};

extern Manager* manager;