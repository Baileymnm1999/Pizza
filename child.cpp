#include "child.h"

std::ostream& operator<<(std::ostream& out, const EnemyType value) {
    const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
    switch(value){
        PROCESS_VAL(Jawa);
        PROCESS_VAL(Guard);
        PROCESS_VAL(Zombie);
        PROCESS_VAL(Fly)
    }
#undef PROCESS_VAL

    return out << s;
}

std::ostream& operator<<(std::ostream& out, const Child value) {
    const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
    switch(value){
        PROCESS_VAL(cWeapon);
        PROCESS_VAL(cMedical);
        PROCESS_VAL(cUtility);
        PROCESS_VAL(cLight);
    }
#undef PROCESS_VAL

    return out << s;
}
