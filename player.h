#ifndef _PLAYER
#define _PLAYER

#include <iostream>
#include <vector>
#include <cstdlib>
#include "point.h"
#include "object.h"
#include "enemy.h"
#include "child.h"

using namespace std;

class Object;
class Weapon;
class Enemy;

class Player {
    private:
        float health, armor;
        int strength, perception, endurance, charisma, intelligence, agility, luck, inventorySizeLimit;
        vector<Object*> inventory;
        Point position;

    public:
        // Constructors
        Player(void);
        Player(int strength, int perception, int endurance, int charisma, int intelligence, int agility, int luck);

        // Getters
        float get_health(void);
        float get_armor(void);
        float get_hunger(void);
        float get_thirst(void);
        int get_strength(void);
        int get_perception(void);
        int get_endurance(void);
        int get_charisma(void);
        int get_intelligence(void);
        int get_agility(void);
        int get_luck(void);
        vector<Object*> get_inventory(void);
        Point get_position(void);
        bool search_inventory(Child type, string itemName);

        // Setters
        void set_health(float health);
        void set_armor(float armor);
        void set_hunger(float hunger);
        void set_thirst(float thirst);
        void set_strength(int strength);
        void set_perception(int perception);
        void set_endurance(int endurance);
        void set_charisma(int charisma);
        void set_intelligence(int intelligence);
        void set_agility(int agility);
        void set_luck(int luck);
        void set_inventory(vector<Object*> inventory);

        // Mutators
        void add_to_inventory(Object* itemToAdd);
        void delete_from_inventory(Object itemToDelete);
        void delete_from_inventory(Object* objPointer);
        void show_inventory(void);
        void go_north(void);
        void go_east(void);
        void go_south(void);
        void go_west(void);
        void show_stats(void);
        void attack(Enemy* enemyToAttack, Weapon* weaponToUse);

};

#endif
