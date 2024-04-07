#include "manager.h"
#include <iostream>

Manager* manager;

Manager::Manager(int frameWidth, int frameHeight) {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        _popObjects[i] = NULL;
    }
    _frameWidth = frameWidth;
    _frameHeight = frameHeight;
}

Manager::~Manager() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i]) {
            delete _popObjects[i];
        }
    }
}

void Manager::add(PopObject* popObject) {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!_popObjects[i]) {
            _popObjects[i] = popObject;
            return;
        }
    }
    // If no empty position found, delete the object
    delete popObject;
    std::cout << "No space available for new object. Object deleted.\n";
}

void Manager::drawFrame(Graphics^ graphics) {
    // Clear background
    graphics->Clear(Color::White);
    // Draw frame rectangle
    graphics->DrawRectangle(Pens::Black, 0, 0, _frameWidth, _frameHeight);
    // Draw all objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i]) {
            _popObjects[i]->draw(graphics);
        }
    }
}

void Manager::move() {
    // Move all objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i]) {
            _popObjects[i]->move();
        }
    }
    // Check for collisions and interact
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i]) {
            for (int j = i + 1; j < MAX_OBJECTS; j++) {
                if (_popObjects[j]) {
                    float dx = _popObjects[i]->getX() - _popObjects[j]->getX();
                    float dy = _popObjects[i]->getY() - _popObjects[j]->getY();
                    float distance = sqrt(dx * dx + dy * dy);
                    if (distance < _popObjects[i]->getSize() + _popObjects[j]->getSize()) {
                        _popObjects[i]->interact(_popObjects[j]);
                        _popObjects[j]->interact(_popObjects[i]);
                    }
                }
            }
        }
    }
}

bool Manager::remove(PopObject* popObject) {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] == popObject) {
            _popObjects[i] = NULL;
            delete popObject;
            return true;
        }
    }
    return false;
}
