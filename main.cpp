#include <iostream>
#include <string>
#include "player.h"
#include "map.h"
#include "child.h"
#include "helpers.h"

using namespace std;

int main(void){
string command;
Object tempObject;

    cout << ">";
    while(alive && getline(cin, command)) {

        command = to_lower(command);

        if(contains(command, "go", "walk", "head")) {
            move(command);

        }else if(contains(command, "kill") && contains(command, "self", "myself", "yourself")) {
            alive = try_suicide(command);

        }else if(contains(command, "take", "grab", "pick up")){
            get_object_here(command);

        }else if(contains(command, "drop", "set down")){
            drop_object_here(command);

        }else if(contains(command, "inventory", "items")){
            P1.show_inventory();

        }else if(contains(command, "status", "health", "my status")){
            P1.show_stats();

        }else if(contains(command, "help")){
            show_help();

        }else if(contains(command, "map")){
            if(P1.search_inventory(cUtility, "map")) {
                show_map();
            }else {
                cout << "You don't have a map :(" << endl;
            }
        }else if(contains(command, "attack")){
            Weapon* weapon = NULL;
            for(int i = 0; i < P1.get_inventory().size(); i++) {
                if(contains(command, P1.get_inventory().at(i)->get_name())){
                    weapon = static_cast<Weapon*>(P1.get_inventory().at(i));
                }
            }
            if(weapon != NULL) {
                for(int i = 0; i < GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).size(); i++) {
                    if(contains(command, "jawa") && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_type() == Jawa) {
                        P1.attack(GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i), weapon);
                    }else if(contains(command, "guard") && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_type() == Guard) {
                        P1.attack(GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i), weapon);
                    }else if(contains(command, "zombie") && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_type() == Zombie) {
                        P1.attack(GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i), weapon);
                    }else if(contains(command, "fly") && GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i)->get_type() == Fly) {
                        P1.attack(GAMEMAP.get_enemies(P1.get_position().getX(), P1.get_position().getY()).at(i), weapon);
                    }else {
                        cout << "That is not an enemy here" << endl;
                    }
                }
            }else {
                cout << "You do not have that weapon" << endl;
            }
        }else {
            cout << "I'm not sure what you mean, type 'help' for directions." << endl;
        }

        cout << endl << ">";
    }

    cout << "GAME OVER" << endl << endl;

}
