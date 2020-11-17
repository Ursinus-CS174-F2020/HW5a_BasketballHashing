#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashable.h"
#include "map.h"

class HashNode {
    public:
        Hashable* key;
        Cloneable* value;
        HashNode* next;
        HashNode(Hashable* key, Cloneable* value);
        ~HashNode();
};

class HashTable: public Map {
    private:
        size_t NBins;
        HashNode** table;
        void removeFirst(size_t i);
    public:
        HashTable(size_t NBins);
        ~HashTable();
        void put(Hashable* key, Cloneable* value);
        Cloneable* get(Hashable* key);
        void remove(Hashable* key);
        bool containsKey(Hashable* key);
        Hashable** getKeyList(size_t* N);
};

#endif
