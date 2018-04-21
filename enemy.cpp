#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(void) {

}

Enemy::Enemy(EnemyType thisEnemy) {
    this->thisEnemy = thisEnemy;
    switch(thisEnemy) {
        case Jawa:
            health = 10;
            damagePoints = 10;
            hostile = 0;
            break;

        case Guard:
            health = 50;
            damagePoints = 50;
            hostile = 1;
            break;

        case Zombie:
            health = 20;
            damagePoints = 50;
            hostile = 1;
            break;

        case Fly:
            health = 100;
            damagePoints = 100;
            hostile = 0;
            break;
    }
}

void Enemy::set_health(float health) {
    this->health = health;
}

void Enemy::set_damage_points(float damagePoints) {
    this->damagePoints = damagePoints;
}

void Enemy::set_hostile(bool hostile) {
    this->hostile = hostile;
}

void Enemy::set_inventory(vector<Object*> inventory) {
    this->inventory = inventory;
}

void Enemy::add_item(Object* item) {
    inventory.push_back(item);
}

float Enemy::get_health(void) {
    return health;
}

EnemyType Enemy::get_type(void) {
    return thisEnemy;
}

float Enemy::get_damage_points(void) {
    return damagePoints;
}

vector<Object*> Enemy::get_inventory(void) {
    return inventory;
}

bool Enemy::is_hostile(void) {
    return hostile;
}

void Enemy::attack(Player* dumbAss) {
    if(dumbAss->get_luck() < rand() % 10){
        float newHealth = dumbAss->get_health() - damagePoints;
        dumbAss->set_health(newHealth);
        cout << "The " << thisEnemy << " attacked you and did " << damagePoints << " points of damage :/" << endl;
    }else {
        cout << "The " << thisEnemy << " tried to attack you but luckily, for you, they slipped on your ego" << endl;
    }
    if(dumbAss->get_health() <= 0) {
        alive = 0;
    }
}
