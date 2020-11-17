#include "hashable.h"


HashableString::HashableString(string s) {
    this->s = s;
}

size_t HashableString::getHash() {
    const char* c = s.c_str();
    // TODO: Fill this in
    return 0;
}

bool HashableString::equals(Hashable* other) {
    HashableString* otherStr = (HashableString*)other;
    return s.compare(otherStr->s) == 0;
}

Cloneable* HashableString::clone() {
    return new HashableString(s);
}


HashableInt::HashableInt(int i) {
    this->i = i;
}

size_t HashableInt::getHash() {
    return (size_t) i;
}

bool HashableInt::equals(Hashable* other) {
    HashableInt* otherInt = (HashableInt*)other;
    return i == otherInt->i;
}

Cloneable* HashableInt::clone() {
    return new HashableInt(i);
}