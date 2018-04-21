#include "helpers.h"

using namespace std;

Map GAMEMAP;
Player P1;
bool alive = 1;

string to_lower(string stringToLower) {
    for(int i = 0; i < stringToLower.size(); i++) {
        stringToLower.at(i) = tolower(stringToLower.at(i));
    }
    return stringToLower;
}

bool contains(string container, string str1) {
    return container.find(str1) != std::string::npos;
}

bool contains(string container, string str1, string str2) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3, string str4) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos
        || container.find(str4) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3, string str4, string str5) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos
        || container.find(str4) != std::string::npos
        || container.find(str5) != std::string::npos);
}

void get_object_here(string objectToGet) {
    vector<Object*> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());

    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            if(contains(objectToGet, to_lower(itemsHere.at(i)->get_name()))) {
                P1.add_to_inventory(itemsHere.at(i));
                GAMEMAP.delete_object(P1.get_position().getX(), P1.get_position().getY(), itemsHere.at(i)->get_name());
                cout << "You took the " << itemsHere.at(i)->get_name() << endl;
            }else {
                cout << "That is not an object here." << endl;
            }
        }
    }else {
        cout << "That is not an object here." << endl;
    }
}

void drop_object_here(string command) {
    for(int i = 0; i < P1.get_inventory().size(); i++) {
        if(contains(command, P1.get_inventory().at(i)->get_name())) {
            GAMEMAP.add_object(P1.get_inventory().at(i), P1.get_position().getX(), P1.get_position().getY());
            vector<Object*> newInventory = P1.get_inventory();
            cout << "You dropped the " << newInventory.at(i)->get_name() << endl;
            newInventory.erase(newInventory.begin() + i);
            P1.set_inventory(newInventory);
        }
    }
}

void see_obstacles_here(void) {
    vector<Structure*> structuresHere;
    int x, y;
    string direction;
    for(int i = 0; i < 4; i++){
        switch(i) {
            case 0:
                x = P1.get_position().getX();
                y = P1.get_position().getY() + 1;
                direction = "to your north.";
                break;
            case 1:
                x = P1.get_position().getX() + 1;
                y = P1.get_position().getY();
                direction = "to your east.";
                break;
            case 2:
                x = P1.get_position().getX();
                y = P1.get_position().getY() - 1;
                direction = "to your south.";
                break;
            case 3:
                x = P1.get_position().getX() - 1;
                y = P1.get_position().getY();
                direction = "to your west.";
                break;
        }
        structuresHere = GAMEMAP.get_structures(x, y);
        if(structuresHere.size() != 0) {
            for(int i = 0; i < structuresHere.size(); i++) {
                if(structuresHere.at(i)->get_class() == cWall) {
                    cout << "There is a wall " << direction << endl;
                }else if(structuresHere.at(i)->get_class() == cFoliage){
                    cout << "There is dense foliage " << direction << endl;
                }else if(structuresHere.at(i)->get_class() == cAbyss){
                    cout << "There is a deep abyss " << direction << " You need a rope to get across." << endl;
                }else if(structuresHere.at(i)->get_class() == cHill){
                    cout << "There is a hill " << direction << " It slopes up from the west and cannot be climbed up. It can be slid down from the east." << endl;
                }
            }
        }
    }
}

void see_enemies_here(void) {
    vector<Enemy*> enemiesHere = GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY());
    for(int i = 0; i < enemiesHere.size(); i++) {
        cout << "There is a " << enemiesHere.at(i)->get_type() << " here. They appear ";
        if(!(enemiesHere.at(i)->is_hostile())) {cout << "not ";}
        cout << "hostile. Their health is " << enemiesHere.at(i)->get_health() << endl;
    }
}

void see_objects_here(void) {
    vector<Object*> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());
    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            cout << "There is a " << itemsHere.at(i)->get_name() << " here." << endl;
        }
    }
    see_obstacles_here();
    see_enemies_here();
}

bool try_suicide(string command) {
    if(contains(command, "rope")) {
        if(P1.search_inventory(cUtility, "rope")) {
            cout << "You hung yourself" << endl;
            return 0;
        }else {
            cout << "You don't have a rope :(" << endl;
        }
    }else if(contains(command, "sword")){
        if(P1.search_inventory(cWeapon, "sword")) {
            cout << "You stabbed yourself" << endl;
            return 0;
        }else {
            cout << "You don't have a sword :(" << endl;
        }
    }else {
        cout << "Kill yourself with?" << endl;
    }
    return 1;
}

void move(string moveCommand) {
    vector<Structure*> structuresHere;

    if(contains(moveCommand, "north")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX(), P1.get_position().getY() + 1);
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go north, a wall blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cFoliage){
                cout << "Can't go north, dense foliage blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cAbyss){
                if(P1.search_inventory(cUtility, "rope")) {
                    cout << "You used the rope to get across the abyss." << endl;
                    P1.go_north();
                }else {
                    cout << "Can't go north, a deep abyss blocks your path and you do not have a rope." << endl;
                    blocked = 1;
                }
            }
        }
        if(!blocked) {
            P1.go_north();
        }
    }else if(contains(moveCommand, "east")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX() + 1, P1.get_position().getY());
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go east, a wall blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cFoliage){
                cout << "Can't go east, dense foliage blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cAbyss){
                if(P1.search_inventory(cUtility, "rope")) {
                    cout << "You used the rope to get across the abyss." << endl;
                    P1.go_east();
                }else {
                    cout << "Can't go east, a deep abyss blocks your path and you do not have a rope." << endl;
                    blocked = 1;
                }
            }else if(structuresHere.at(i)->get_class() == cHill){
                cout << "Can't go east, a steep hill is there." << endl;
                blocked = 1;
            }
        }
        if(!blocked) {
            P1.go_east();
        }
    }else if(contains(moveCommand, "south")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX(), P1.get_position().getY() - 1);
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go south, a wall blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cFoliage){
                cout << "Can't go south, dense foliage blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cAbyss){
                if(P1.search_inventory(cUtility, "rope")) {
                    cout << "You used the rope to get across the abyss." << endl;
                    P1.go_south();
                }else {
                    cout << "Can't go south, a deep abyss blocks your path and you do not have a rope." << endl;
                    blocked = 1;
                }
            }
        }
        if(!blocked) {
            P1.go_south();
        }
    }else if(contains(moveCommand, "west")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX() - 1, P1.get_position().getY());
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go west, a wall blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cFoliage){
                cout << "Can't go west, dense foliage blocks your path." << endl;
                blocked = 1;
            }else if(structuresHere.at(i)->get_class() == cAbyss){
                if(P1.search_inventory(cUtility, "rope")) {
                    cout << "You used the rope to get across the abyss." << endl;
                    P1.go_west();
                }else {
                    cout << "Can't go west, a deep abyss blocks your path and you do not have a rope." << endl;
                    blocked = 1;
                }
            }else if(structuresHere.at(i)->get_class() == cHill){
                cout << "You slid down the hill." << endl;
                P1.go_west();
            }
        }
        if(!blocked) {
            P1.go_west();
        }
    }

    see_objects_here();
}

void show_help(void) {
    cout << "Welcome to Pizza, a game thought up by visionaries Bailey and Spencer" << endl << endl
    << "Pizza is a comand line game where the user controls their player by typing in commands. Most commands will be in the form '[verb] [noun]' such as 'grab sword' or 'go north'. Some commands may take a few more options such as 'attack guard with sword' or 'unlock door with key'. Be careful with your commands, mixing keywords may cause multiple things to happen at once. This may be problematic if you are new and still learning, but could be used as an advantage for an experienced user." << endl << endl
    << "[Commands]" << endl
    << "go [direction]:" << endl
    << "        *[direction] {north, east, west, south}" << endl
    << "take [item]" << endl
    << "        *[item] {common sword, potion of healing, rope, etc}" << endl
    << "            *NOTE [item] must be the exact name of the item you wish to grab" << endl
    << "attack [enemy] with [weapon]" << endl
    << "        *[enemy] {guard, zombie, your mom, etc}" << endl
    << "            *NOTE [enemy] must be the exact name of the enemy you wish to attack" << endl
    << "        *[weapon] {sword, daggar, ar-15, etc}" << endl
    << "            *NOTE [weapon] must be the exact name of the weapon you wish to attack with" << endl
    << "There are other commands such as show map that can be used through the game" << endl << endl
    << "[Story]" << endl
    << "You are an ex-officer for the Israeli Army, whose fiance (Jenn-Long(a)-y) was kidnapped by gang of Jawas. It is your duty to rescue her! On your journey across dangerous terrains, you encounter many obstacles that stand in the way of Jennay’s freedom.  Will you save her from eminent death, or die trying?" << endl << endl;
}

void show_map(void) {
    cout << "17██████████████████████                  " << endl;
    cout << "16██████  ██████████████  Isreali Customs " << endl;
    cout << "15██████  ██████████████                  " << endl;
    cout << "14██████  ██████████████                  " << endl;
    cout << "13██████  ████████████████                " << endl;
    cout << "12██^^^^  //    ████████████              " << endl;
    cout << "11██^^^^  //    ██████████████████__      " << endl;
    cout << "10██^^^^  //                        ██████" << endl;
    cout << "09██^^^^  //    ██████████████████  ██████" << endl;
    cout << "08██████  ████████████████████████  ██████" << endl;
    cout << "07██████  ████████████████████████  ██████" << endl;
    cout << "06██████  ████████████__██__██__██  ██████" << endl;
    cout << "05██           ]  [   __  __  __    ██████" << endl;
    cout << "04  |     ████████████  ██  ██  ██  ██████" << endl;
    cout << "03██  __  ████████████████████████████████" << endl;
    cout << "02████  ██████████████████████████████████" << endl;
    cout << "01████████████████████████████████████████" << endl;
    cout << "  0102030405060708091011121314151617181920" << endl;
    cout << "Your coords: " << P1.get_position() << endl;
}

void piss_off_enemys_here(void) {
    for(int i = 0; i < GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).size(); i++) {
        if(P1.get_luck() < rand() % 10 && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->is_hostile() && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_health() >= 0.1) {
            GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->attack(&P1);
        }else if(GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_health() < 0.1) {
            GAMEMAP.kill_enemy(P1.get_position().getX(), P1.get_position().getY(), GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i));
        }
    }
}
