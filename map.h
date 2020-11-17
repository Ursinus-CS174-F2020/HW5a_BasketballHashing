#ifndef MAP_H
#define MAP_H

#include "hashable.h"
#include "cloneable.h"

class Map {
    public:
        virtual ~Map(){};
        virtual void put(Hashable* key, Cloneable* value) = 0;
        virtual Cloneable* get(Hashable* key) = 0;
        virtual void remove(Hashable* key) = 0;
        virtual bool containsKey(Hashable* key) = 0;
        virtual Hashable** getKeyList(size_t* N) = 0;
        size_t numOps;
        void resetOps() {
            numOps = 0;
        }
        size_t getOps() {
            return numOps;
        }
};


#endif
