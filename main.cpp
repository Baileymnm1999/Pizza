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

        if( !(contains(command, "exit", "items", "inventory", "health", "status") || contains(command, "help"))) {
            piss_off_enemys_here();
        }

        if(contains(command, "go", "walk", "head")) {
            if(contains(command, "9")) {
                for(int i = 0; i < 9; i++) {
                    move(command);
                }
            }else if(contains(command, "8")) {
                for(int i = 0; i < 8; i++) {
                    move(command);
                }
            }else if(contains(command, "7")) {
                for(int i = 0; i < 7; i++) {
                    move(command);
                }
            }else if(contains(command, "6")) {
                for(int i = 0; i < 6; i++) {
                    move(command);
                }
            }else if(contains(command, "5")) {
                for(int i = 0; i < 5; i++) {
                    move(command);
                }
            }else if(contains(command, "4")) {
                for(int i = 0; i < 4; i++) {
                    move(command);
                }
            }else if(contains(command, "3")) {
                for(int i = 0; i < 3; i++) {
                    move(command);
                }
            }else if(contains(command, "2")) {
                for(int i = 0; i < 2; i++) {
                    move(command);
                }
            }else{
                move(command);
            }

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
        }else if(contains(command, "use")){
            for(int i = 0; i < P1.get_inventory().size(); i++) {
                if(P1.get_inventory().at(i)->get_class() == cMedical && contains(command, to_lower(P1.get_inventory().at(i)->get_name()))) {
                    cout << "You used " << P1.get_inventory().at(i)->get_name() << endl;
                    static_cast<Medical*>(P1.get_inventory().at(i))->use(&P1);
                }
            }
        }else if(command == "exit") {
		    cout << "Thank you for giving up." << endl;
		    return 0;

        }else {
            cout << "I'm not sure what you mean, type 'help' for directions." << endl;
        }

        if(P1.get_position().getX() == 17 && P1.get_position().getY() == 11) {
            cout << "Expecting Jenay you leave the checkpoint to the south and find Rick Astley" << endl;
            cout << endl << "YOU WIN" << endl;
            return 0;
        }


        cout << endl << ">";
    }

    cout << "GAME OVER" << endl << endl;

}
