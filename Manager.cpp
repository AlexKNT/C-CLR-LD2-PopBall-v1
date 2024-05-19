#include "manager.h"
#include <iostream>
#include "Explosion.h"

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
                if (_popObjects[j] && _popObjects[i]) {
                    float dx = _popObjects[i]->getX() - _popObjects[j]->getX();
                    float dy = _popObjects[i]->getY() - _popObjects[j]->getY();
                    float distance = sqrt(dx * dx + dy * dy);
                    if (distance < _popObjects[i]->getSize() + _popObjects[j]->getSize()) {
                        // Check if objects can interact and exist before interacting
                        if (_popObjects[i]->interactable(_popObjects[j]) && _popObjects[j]->interactable(_popObjects[i])) {
                            _popObjects[i]->interact(_popObjects[j]);
                            _popObjects[j]->interact(_popObjects[i]);

                            // Increment the interaction count for both objects
                            _popObjects[i]->interactionCount++;
                            _popObjects[j]->interactionCount++;
                        }
                    }
                }
            }
        }
    }

    // Check for objects that have interacted with at least two other objects and explode them
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] && _popObjects[i]->interactionCount >= 2) {
            // Create an explosion at the position of the object
            Explosion* explosion = new Explosion(_frameWidth, _frameHeight, _popObjects[i]->getX(), _popObjects[i]->getY());

            // Add the explosion to the manager
            add(explosion);

            // Delete the original object
            remove(_popObjects[i]);
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

void Manager::destroyAll() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i]) {
            Explosion* explosion = new Explosion(_frameWidth, _frameHeight, _popObjects[i]->getX(), _popObjects[i]->getY());

            // Delete the original object
            delete _popObjects[i];
            _popObjects[i] = NULL; // Set the pointer to NULL to avoid dangling pointers
        }
    }
}

PopObject* Manager::nearest(PopObject* popObject)
{
    PopObject* nearest = NULL;
	float minDistance = 9999999;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] && _popObjects[i] != popObject) {
			float dx = _popObjects[i]->getX() - popObject->getX();
			float dy = _popObjects[i]->getY() - popObject->getY();
			float distance = sqrt(dx * dx + dy * dy);
            if (distance < minDistance) {
				minDistance = distance;
				nearest = _popObjects[i];
			}
		}
	}
	return nearest;
}

PopObject* Manager::nearestFriend(PopObject* popObject)
{
	PopObject* nearest = NULL;
	float minDistance = 9999999;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] && _popObjects[i] != popObject && typeid(*_popObjects[i]) == typeid(*popObject)) {
			float dx = _popObjects[i]->getX() - popObject->getX();
			float dy = _popObjects[i]->getY() - popObject->getY();
			float distance = sqrt(dx * dx + dy * dy);
            if (distance < minDistance) {
				minDistance = distance;
				nearest = _popObjects[i];
			}
		}
	}
	return nearest;
}

PopObject* Manager::nearestAlien(PopObject* popObject)
{
	PopObject* nearest = NULL;
	float minDistance = 9999999;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] && _popObjects[i] != popObject && typeid(*_popObjects[i]) != typeid(*popObject)) {
			float dx = _popObjects[i]->getX() - popObject->getX();
			float dy = _popObjects[i]->getY() - popObject->getY();
			float distance = sqrt(dx * dx + dy * dy);
            if (distance < minDistance) {
				minDistance = distance;
				nearest = _popObjects[i];
			}
		}
	}
	return nearest;
}

int Manager::countOf(const type_info* type)
{
	int count = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (_popObjects[i] && typeid(*_popObjects[i]) == *type) {
			count++;
		}
	}
	return count;
}

void Manager::place(PopObject* popObject) {
    bool isIntersecting;
    int x, y;

    do {
        isIntersecting = false;

        // Generate random position within the frame
        x = rand() % _frameWidth;
        y = rand() % _frameHeight;

        // Check if the new object intersects with any existing object
        for (int i = 0; i < MAX_OBJECTS; i++) {
            if (_popObjects[i]) {
                float dx = x - _popObjects[i]->getX();
                float dy = y - _popObjects[i]->getY();
                float distance = sqrt(dx * dx + dy * dy);

                if (distance < popObject->getSize() + _popObjects[i]->getSize()) {
                    isIntersecting = true;
                    break;
                }
            }
        }
    } while (isIntersecting);

    // Set the position of the new object
    popObject->setPos(x, y);

    // Add the new object to the collection
    add(popObject);
}
