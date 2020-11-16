#ifndef HASHABLE_H
#define HASHABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;


class Hashable {
    public:
        virtual ~Hashable() {};
        virtual size_t getHash();
        virtual bool equals(Hashable* other);
};

class HashableString: public Hashable {
    public:
        string s;    
        HashableString(string s);
        size_t getHash();
        bool equals(Hashable* other);
};

#endif
