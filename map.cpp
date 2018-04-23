#include "map.h"
using namespace std;

Map::Map(void) {

    // PROMPTS
    prompts[2][9] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[2][10] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[2][11] = "This is the forest of suicide... Many have taken their lives here\nThere is a dead guy here. He seems to have take his life.";
    prompts[2][12] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[3][9] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[3][10] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[3][11] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[3][12] = "This is the forest of suicide... Many have taken their lives here.";
    prompts[4][12] = "North of you is a tunnel, no telling what hides on the other end";
    prompts[9][10] = "You are in a creepy ass hallway.";
    prompts[10][10] = "You are in a creepy ass hallway.";
    prompts[11][10] = "You are in a creepy ass hallway.";
    prompts[12][10] = "You are in a creepy ass hallway.";
    prompts[13][10] = "You are in a creepy ass hallway.";
    prompts[14][10] = "You are in a creepy ass hallway.";
    prompts[15][10] = "You are in a creepy ass hallway.";
    prompts[13][6] = "This room is covered in blood, smells of menstrual fluid...";
    prompts[13][5] = "This is the town center. The rooms hide many secrets.";

    // OBJECTS
    Utility* u1 = new Utility;
    u1->set_name("map");

    Utility* u2 = new Utility;
    u2->set_name("leprechaun [+3 Luck]");

    Utility* u3 = new Utility;
    u3->set_name("rope");

    Utility* u4 = new Utility;
    u4->set_name("key");

    Utility* u5 = new Utility;
    u5->set_name("Guard Uniform");

    Utility* u6 = new Utility;
    u6->set_name("Playboy Volume 4 Edition 2");

    Weapon* a1 = new Weapon;
    a1->set_name("sword");
    a1->set_damage_points(5);

    Weapon* a2 = new Weapon;
    a2->set_name("Glock 19");
    a2->set_damage_points(30);

    Weapon* a3 = new Weapon;
    a3->set_name("Dildo");
    a3->set_damage_points(50);

    Weapon* a4 = new Weapon;
    a4->set_name("sick diss");
    a4->set_damage_points(75);

    Medical* m1 = new Medical;
    m1->set_name("Potion");
    m1->set_revive_points(50);
    m1->set_uses(1);

    Medical* m2 = new Medical;
    m2->set_name("Bandages");
    m2->set_revive_points(20);
    m2->set_uses(5);

    Medical* m3 = new Medical;
    m3->set_name("Ointment");
    m3->set_revive_points(30);
    m3->set_uses(2);

    objectGrid[3][5].push_back(u1);
    objectGrid[11][6].push_back(u2);
    objectGrid[2][11].push_back(u3);
    objectGrid[4][16].push_back(u4);
    objectGrid[2][11].push_back(u5);
    objectGrid[1][4].push_back(a1);
    objectGrid[2][11].push_back(a2);
    objectGrid[15][6].push_back(a3);
    objectGrid[3][2].push_back(m1);
    objectGrid[11][4].push_back(m2);

    // ENEMIES
    Enemy* e1 = new Enemy(Jawa);
    e1->add_item(u6);

    Enemy* e2 = new Enemy(Fly);

    Enemy* e3 = new Enemy(Zombie);

    Enemy* e4 = new Enemy(Guard);
    e4->set_health(100);

    Enemy* e5 = new Enemy(Jawa);
    e5->set_damage_points(20);
    e5->add_item(a4);
    e5->add_item(m3);


    enemyGrid[2][4].push_back(e1);
    enemyGrid[12][10].push_back(e2);
    enemyGrid[(rand() % 2) + 2][(rand() % 4) + 9].push_back(e3);
    enemyGrid[17][10].push_back(e4);
    enemyGrid[15][4].push_back(e5);

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

string Map::get_prompt(int x, int y) {
    return prompts[x][y];
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
