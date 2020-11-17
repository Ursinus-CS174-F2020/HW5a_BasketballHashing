#ifndef LINKEDMAP_H
#define LINKEDMAP_H

#include "hashable.h"
#include "map.h"

class LinkedNode {
    public:
        Hashable* key;
        Cloneable* value;
        LinkedNode* next;
        LinkedNode(Hashable* key, Cloneable* value);
        ~LinkedNode();
};

class LinkedMap: public Map {
    private:
        void removeFirst();
    public:
        LinkedNode* head;
        LinkedMap();
        ~LinkedMap();
        // It is assumed that the key is both Hashable and Cloneable
        void put(Hashable* key, Cloneable* value);
        Cloneable* get(Hashable* key);
        void remove(Hashable* key);
        bool containsKey(Hashable* key);
        Hashable** getKeyList(size_t* N);
};

#endif