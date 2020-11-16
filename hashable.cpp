#include "hashable.h"

size_t Hashable::getHash() {
    printf("Warning: calling Hashable::getHash on base class\n");
    return (size_t)this;
}

bool Hashable::equals(Hashable* other) {
    printf("Warning: calling Hashable::equals() on base class\n");
    return false;
}


HashableString::HashableString(string s) {
    this->s = s;
}

size_t HashableString::getHash() {
    const char* c = s.c_str();
    int i = 0;
    size_t hash = 0;
    while (c[i] != '\0') {
        hash = (size_t)c[i] + 31*hash;
        i++;
    }
    return hash;
}

bool HashableString::equals(Hashable* other) {
    HashableString* otherStr = (HashableString*)other;
    return s.compare(otherStr->s) == 0;
}