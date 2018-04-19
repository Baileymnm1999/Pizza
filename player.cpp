#include <string>
#include <cmath>
#include "player.h"
#include "helpers.h"
using namespace std;

Player::Player(void) {
    position.setPoint(3, 4);
    health = 100;
    armor = 0;
    strength = perception = endurance = charisma = intelligence = agility = luck = 5;
    inventorySizeLimit = 5;
}

Player::Player(int strength, int perception, int endurance, int charisma, int intelligence, int agility, int luck) {
    position.setPoint(0, 0);
    health = 100;
    armor = 0;
    this->strength = strength;
    this->perception = perception;
    this->endurance = endurance;
    this->charisma = charisma;
    this->intelligence = intelligence;
    this->agility = agility;
    this->luck = luck;
}

float Player::get_health(void) {
    return health;
}

float Player::get_armor(void) {
    return armor;
}

int Player::get_strength(void) {
    return strength;
}

int Player::get_perception(void) {
    return perception;
}

int Player::get_endurance(void) {
    return endurance;
}

int Player::get_charisma(void) {
    return charisma;
}

int Player::get_intelligence(void) {
    return intelligence;
}

int Player::get_agility(void) {
    return agility;
}

int Player::get_luck(void) {
    return luck;
}

Point Player::get_position(void) {
    return position;
}





void Player::set_health(float health) {
    this->health = health;
}

void Player::set_armor(float armor) {
    this->armor = armor;
}

void Player::set_strength(int strength) {
    this->strength = strength;
}

void Player::set_perception(int perception) {
    this->perception = perception;
}

void Player::set_endurance(int endurance) {
    this->endurance = endurance;
}

void Player::set_charisma(int charisma) {
    this->charisma = charisma;
}

void Player::set_intelligence(int intelligence) {
    this->intelligence = intelligence;
}

void Player::set_agility(int agility) {
    this->agility = agility;
}

void Player::set_luck(int luck) {
    this->luck = luck;
}

vector<Object*> Player::get_inventory(void) {
    return inventory;
}

void Player::show_inventory(void) {
    cout << endl << "Your Inventory" << endl;
    for(int i = 0; i < inventory.size(); i++) {
        cout << i+1 << ": " << inventory.at(i)->get_name() << endl;
    }
}

void Player::delete_from_inventory(Object* itemToDelete) {
    itemToDelete->remove_from(inventory);
}

// void Player::delete_from_inventory(Object* objPointer) {
//     *objPointer->remove_from(inventory);
// }

void Player::add_to_inventory(Object* itemToAdd) {
    if(inventory.size() < inventorySizeLimit) {
        inventory.push_back(itemToAdd);
    }else {
        cout << "There is not enough room in your inventory!" << endl;
    }
}

void Player::set_inventory(vector<Object*> inventory) {
    this->inventory = inventory;
}

bool Player::search_inventory(Child type, string itemName) {
    for(int i = 0; i < inventory.size(); i++) {
        if(inventory.at(i)->get_class() == type && inventory.at(i)->get_name() == itemName) {
            return true;
        }
    }
    return false;
}

void Player::go_north(void) {
    position.setPoint(position.getX(), position.getY() + 1);
}

void Player::go_east(void) {
    position.setPoint(position.getX() + 1, position.getY());
}

void Player::go_south(void) {
    position.setPoint(position.getX(), position.getY() - 1);
}

void Player::go_west(void) {
    position.setPoint(position.getX() - 1, position.getY());
}

void Player::show_stats(void) {
    cout << endl << "Status" << endl;
    cout << "Health: " << health << endl;
    cout << "Armor: " << armor << endl;
}

void Player::attack(Enemy* enemyToAttack, Weapon* weaponToUse) {
    if(search_inventory(cWeapon, weaponToUse->get_name())) {
        if(luck > (rand()%10)) {
            float beginHealth = enemyToAttack->get_health();
            float damage = weaponToUse->get_damage_points();
            float finalHealth = beginHealth - damage;
            cout << "You attacked the " << enemyToAttack->get_type() << " and did " << damage << " points of damage" << endl;
            enemyToAttack->set_health(finalHealth);
            if(!(enemyToAttack->is_hostile())) {
                enemyToAttack->set_hostile(1);
                cout << "The " << enemyToAttack->get_type() << " is now hostile!" << endl;
            }
            if(finalHealth < 0.1) {
                GAMEMAP.kill_enemy(static_cast<int>(position.getX()), static_cast<int>(position.getY()), enemyToAttack);
            }
        }else {
            cout << "You attempted to attack the " << enemyToAttack->get_type() << " and missed" << endl;
            if(!(enemyToAttack->is_hostile()) && (luck < (rand() % 10))) {
                enemyToAttack->set_hostile(1);
                cout << "The " << enemyToAttack->get_type() << " is now hostile!" << endl;
            }else if(!(enemyToAttack->is_hostile())){
                cout << "The " << enemyToAttack->get_type() << " did not notice you..." << endl;
            }
        }
        cout << "The " << enemyToAttack->get_type() << " has " << enemyToAttack->get_health() << " health" << endl;
    }else {
        //cout << "You do not have a " << weaponToUse->get_name() << endl;
    }
    if(enemyToAttack->is_hostile() && enemyToAttack->get_health() > 0.1) {
        enemyToAttack->attack(this);
    }
}
