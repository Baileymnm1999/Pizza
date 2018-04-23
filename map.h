#ifndef _MAP
#define _MAP

#include <iostream>
#include <string>
#include "object.h"
#include "structure.h"
#include "enemy.h"


using namespace std;

class Enemy;
class Object;
class Structure;

class Map {
    private:
        int width, height;
        vector<Object*> objectGrid[20][20];
        vector<Structure*> structureGrid[20][20];
        vector<Enemy*> enemyGrid[20][20];
        string prompts[20][20];


    public:
        Map(void);

        void add_object(Object*, int x, int y);

        vector<Object*> get_objects(int x, int y);
        vector<Structure*> get_structures(int x, int y);
        vector<Enemy*> get_enemies(int x, int y);
        string get_prompt(int x, int y);

        void delete_object(int x, int y, string itemName);
        void kill_enemy(int x, int y, Enemy* enemyToKill);
};


#endif
