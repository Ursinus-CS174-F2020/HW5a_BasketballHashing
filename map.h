#ifndef MAP_H
#define MAP_H

#include "hashable.h"

class Map {
    public:
        virtual ~Map(){};
        virtual void put(Hashable* key, void* value) = 0;
        virtual void* get(Hashable* key) = 0;
        virtual void* remove(Hashable* key) = 0;
        virtual bool containsKey(Hashable* key) = 0;
        virtual Hashable** getKeyList(size_t* N) = 0;
        virtual void** getValueList(size_t* N) = 0;
};


#endif
