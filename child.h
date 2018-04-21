#ifndef _CHILD
#define _CHILD

#include <iostream>

enum Child { Nothing, cWeapon, cMedical, cUtility, cLight };

enum StructType { None, cWall, cDoor, cFoliage, cAbyss, cGate };

enum EnemyType { Jawa, Guard, Zombie, Fly};

enum Direction { North, East, South, West};

std::ostream& operator<<(std::ostream& out, const EnemyType value);

#endif
