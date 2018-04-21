#include "map.h"
using namespace std;

Map::Map(void) {

    // OBJECTS
    Utility* u1 = new Utility;
    u1->set_name("map");

    Utility* u2 = new Utility;
    u2->set_name("leprechaun [+3 Luck]");

    Utility* u3 = new Utility;
    u3->set_name("rope");

    Utility* u4 = new Utility;
    u4->set_name("key");

    Weapon* a1 = new Weapon;
    a1->set_name("sword");
    a1->set_damage_points(2);
    a1->set_durability_points(10);

    Weapon* a2 = new Weapon;
    a2->set_name("ar-15");
    a2->set_damage_points(50);

    Medical* m1 = new Medical;
    m1->set_name("Potion");
    m1->set_revive_points(50);
    m1->set_uses(1);

    objectGrid[3][5].push_back(u1);
    objectGrid[4][16].push_back(u4);
    objectGrid[3][2].push_back(m1);
    objectGrid[1][4].push_back(a1);
    objectGrid[2][11].push_back(u3);

    // ENEMIES
    Enemy* e1 = new Enemy(Jawa);
    e1->add_item(a2);

    Enemy* e2 = new Enemy(Fly);

    enemyGrid[2][4].push_back(e1);
    enemyGrid[2][5].push_back(e2);

    // STRUCTURES
    Wall* w1 = new Wall;
    Foliage* f1 = new Foliage;
    Abyss* h1 = new Abyss;
    Hill* h2 = new Hill;
    Door* d1 = new Door;
    d1->close();
    d1->unlock();
    Door* d2 = new Door;
    d2->close();
    d2->unlock();
    Door* d3 = new Door;
    d3->close();
    d3->unlock();
    Door* d4 = new Door;
    d4->close();
    d4->lock();
    Door* d5 = new Door;
    d5->close();
    d5->unlock();
    Door* d6 = new Door;
    d6->close();
    d6->unlock();
    Door* d7 = new Door;
    d7->close();
    d7->lock();
    Door* d8 = new Door;
    d8->close();
    d8->lock();


    structureGrid[0][4].push_back(w1);
    structureGrid[1][3].push_back(w1);
    structureGrid[1][4].push_back(d1);
    structureGrid[1][5].push_back(w1);
    structureGrid[1][9].push_back(f1);
    structureGrid[1][10].push_back(f1);
    structureGrid[1][11].push_back(f1);
    structureGrid[1][12].push_back(f1);
    structureGrid[2][2].push_back(w1);
    structureGrid[2][6].push_back(w1);
    structureGrid[2][8].push_back(f1);
    structureGrid[2][13].push_back(f1);
    structureGrid[3][1].push_back(w1);
    structureGrid[3][2].push_back(d2);
    structureGrid[3][6].push_back(w1);
    structureGrid[3][7].push_back(w1);
    structureGrid[3][8].push_back(f1);
    structureGrid[3][13].push_back(f1);
    structureGrid[3][14].push_back(w1);
    structureGrid[3][15].push_back(w1);
    structureGrid[3][16].push_back(w1);
    structureGrid[4][2].push_back(w1);
    structureGrid[4][17].push_back(w1);
    structureGrid[5][3].push_back(w1);
    structureGrid[5][4].push_back(w1);
    structureGrid[5][6].push_back(w1);
    structureGrid[5][7].push_back(w1);
    structureGrid[5][8].push_back(f1);
    structureGrid[5][9].push_back(h2);
    structureGrid[5][10].push_back(h2);
    structureGrid[5][11].push_back(h2);
    structureGrid[5][12].push_back(h2);
    structureGrid[5][13].push_back(f1);
    structureGrid[5][14].push_back(w1);
    structureGrid[5][15].push_back(w1);
    structureGrid[5][16].push_back(w1);
    structureGrid[6][4].push_back(w1);
    structureGrid[6][6].push_back(w1);
    structureGrid[6][8].push_back(f1);
    structureGrid[6][13].push_back(f1);
    structureGrid[7][4].push_back(f1);
    structureGrid[7][6].push_back(f1);
    structureGrid[7][8].push_back(f1);
    structureGrid[7][13].push_back(f1);
    structureGrid[8][4].push_back(f1);
    structureGrid[8][5].push_back(h1);
    structureGrid[8][6].push_back(f1);
    structureGrid[8][9].push_back(w1);
    structureGrid[8][11].push_back(w1);
    structureGrid[8][12].push_back(w1);
    structureGrid[9][4].push_back(f1);
    structureGrid[9][6].push_back(f1);
    structureGrid[9][9].push_back(w1);
    structureGrid[9][11].push_back(w1);
    structureGrid[10][4].push_back(w1);
    structureGrid[10][6].push_back(w1);
    structureGrid[10][9].push_back(w1);
    structureGrid[10][11].push_back(w1);
    structureGrid[11][3].push_back(w1);
    structureGrid[11][4].push_back(d3);
    structureGrid[11][6].push_back(d4);
    structureGrid[11][7].push_back(w1);
    structureGrid[11][9].push_back(w1);
    structureGrid[11][11].push_back(w1);
    structureGrid[12][4].push_back(w1);
    structureGrid[12][6].push_back(w1);
    structureGrid[12][9].push_back(w1);
    structureGrid[12][11].push_back(w1);
    structureGrid[13][3].push_back(w1);
    structureGrid[13][4].push_back(d5);
    structureGrid[13][6].push_back(d6);
    structureGrid[13][7].push_back(w1);
    structureGrid[13][9].push_back(w1);
    structureGrid[13][11].push_back(w1);
    structureGrid[14][4].push_back(w1);
    structureGrid[14][6].push_back(w1);
    structureGrid[14][9].push_back(w1);
    structureGrid[14][11].push_back(w1);
    structureGrid[15][3].push_back(w1);
    structureGrid[15][4].push_back(d7);
    structureGrid[15][6].push_back(d8);
    structureGrid[15][7].push_back(w1);
    structureGrid[15][9].push_back(w1);
    structureGrid[15][11].push_back(w1);
    structureGrid[16][4].push_back(w1);
    structureGrid[16][6].push_back(w1);
    structureGrid[16][9].push_back(w1);
    structureGrid[16][11].push_back(w1);
    structureGrid[17][3].push_back(w1);
    structureGrid[18][4].push_back(w1);
    structureGrid[18][5].push_back(w1);
    structureGrid[18][6].push_back(w1);
    structureGrid[18][7].push_back(w1);
    structureGrid[18][8].push_back(w1);
    structureGrid[18][9].push_back(w1);
    structureGrid[18][10].push_back(w1);

}

void Map::add_object(Object* objectToAdd, int x, int y) {
    objectGrid[x][y].push_back(objectToAdd);
}

vector<Object*> Map::get_objects(int x, int y) {
    return objectGrid[x][y];
}

vector<Structure*> Map::get_structures(int x, int y) {
    return structureGrid[x][y];
}

vector<Enemy*> Map::get_enemies(int x, int y) {
    return enemyGrid[x][y];
}

void Map::delete_object(int x, int y, string itemName) {
    for(int i = 0; i < objectGrid[x][y].size(); i++) {
        if(objectGrid[x][y].at(i)->get_name() == itemName) {
            objectGrid[x][y].erase(objectGrid[x][y].begin() + i);
        }
    }
}

void Map::kill_enemy(int x, int y, Enemy* enemyToKill) {
    for(int i = 0; i < enemyGrid[x][y].size(); i++) {
        if(enemyGrid[x][y].at(i) == enemyToKill && enemyGrid[x][y].at(i)->get_health() < 0.1) {
            for(int i = 0; i < enemyToKill->get_inventory().size(); i++) {
                objectGrid[x][y].push_back(enemyToKill->get_inventory().at(i));
                cout << "The " << enemyToKill->get_type() << " dropped a " << enemyToKill->get_inventory().at(i)->get_name() << endl;
            }
            enemyGrid[x][y].erase(enemyGrid[x][y].begin() + i);
            delete enemyToKill;
            cout << "The " << enemyToKill->get_type() << " died" << endl;
        }
    }
}
