#ifndef LINKEDMAP_H
#define LINKEDMAP_H

#include "hashable.h"
#include "map.h"

class Node {
    public:
        Hashable* key;
        void* value;
        Node* next;
        Node(Hashable* key, void* value);
};

class LinkedMap: public Map {
    private:
        Node* head;
        void removeFirst();
    public:
        LinkedMap();
        ~LinkedMap();
        void put(Hashable* key, void* value);
        void* get(Hashable* key);
        void* remove(Hashable* key);
        bool containsKey(Hashable* key);
        Hashable** getKeyList(size_t* N);
        void** getValueList(size_t* N);
};

#endif