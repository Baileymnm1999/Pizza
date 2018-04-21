#ifndef _ENEMY
#define _ENEMY

#include <string>
#include "helpers.h"
#include "player.h"
#include "child.h"
#include "map.h"
#include "object.h"

using namespace std;

class Player;

class Object;

class Enemy {
    protected:
        vector<Object*> inventory;
        float health, damagePoints;
        bool hostile;
        EnemyType thisEnemy;
    public:
        // Constructors
        Enemy(void);
        Enemy(EnemyType thisEnemy);

        // Setters
        void set_health(float health);
        void set_damage_points(float damagePoints);
        void set_hostile(bool hostile);
        void set_inventory(vector<Object*> inventory);
        void add_item(Object* item);

        // Getters
        EnemyType get_type(void);
        float get_health(void);
        float get_damage_points(void);
        bool is_hostile(void);
        vector<Object*> get_inventory(void);

        void attack(Player* dumbAss);

};

#endif
