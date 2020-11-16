#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashable.h"
#include "map.h"

class HashNode {
    public:
        Hashable* key;
        void* value;
        HashNode* next;
};

class HashTable {
    private:
        size_t NBins;
        HashNode** table;
    public:
        HashTable(size_t NBins);
        ~HashTable();
        void put(Hashable* key, void* value);
        void* get(Hashable* key);
        void* remove(Hashable* key);
        bool containsKey(Hashable* key);
};

#endif
