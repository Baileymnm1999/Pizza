#include "structure.h"

using namespace std;

Structure::Structure(void) {
    structureType = None;
}

StructType Structure::get_class(void) {
    return structureType;
}

Wall::Wall(void) {
    structureType = cWall;
}

Foliage::Foliage(void) {
    structureType = cFoliage;
}

Abyss::Abyss(void) {
    structureType = cAbyss;
}

Gate::Gate(void) {
    isOpen = 0;
    side = North;
    structureType = cGate;
}

void Gate::open(void) {
    this->isOpen = 1;
}

void Gate::close(void) {
    this->isOpen = 0;
}

bool Gate::is_open(void) {
    return isOpen;
}

Direction Gate::get_side(void) {
    return side;
}

Door::Door(void) {
    side = North;
    isOpen = 1;
    isLocked = 0;
    structureType = cDoor;
}

void Door::open(void) {
    this->isOpen = 1;
}

void Door::close(void) {
    this->isOpen = 0;
}

void Door::unlock(void) {
    this->isLocked = 0;
}

void Door::lock(void) {
    this->isLocked = 1;
}

bool Door::is_open(void) {
    return isOpen;
}

bool Door::is_locked(void) {
    return isLocked;
}

Direction Door::get_side(void) {
    return side;
}
