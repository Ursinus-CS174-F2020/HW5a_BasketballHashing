#include <iostream>
#include "hashable.h"

using namespace std;

int main() {
    HashableString s1("Hello");
    cout << "Hello: " << s1.getHash() << endl;
    HashableString s2("CS 174");
    cout << "CS 174: " << s2.getHash() << endl;
    HashableString s3("Computers rock");
    cout << "Computers rock: " << s3.getHash() << endl;
    return 0;
}
