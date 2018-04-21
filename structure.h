#ifndef _STRUCTURE
#define _STRUCTURE

#include "child.h"
#include "player.h"

using namespace std;

class Structure {
    protected:
        StructType structureType;
    public:
        // Constructors
        Structure(void);

        // Getters
        StructType get_class(void);

};

class Wall : public Structure {
    private:

    public:
        // Constructors
        Wall(void);
};

class Foliage : public Structure {
    private:

    public:
        // Constructors
        Foliage(void);
};

class Abyss : public Structure {
    private:

    public:
        // Constructors
        Abyss(void);
};

class Gate : public Structure {
    private:
        Direction side;
        bool isOpen;
    public:
        // Constructors
        Gate(void);

        void open(void);
        void close(void);

        bool is_open(void);
        Direction get_side(void);
};

class Door : public Structure {
    private:
        Direction side;
        bool isOpen, isLocked;
    public:
        // Constructors
        Door(void);

        void open(void);
        void close(void);
        void unlock(void);
        void lock(void);

        bool is_open(void);
        bool is_locked(void);
        Direction get_side(void);
};

#endif
