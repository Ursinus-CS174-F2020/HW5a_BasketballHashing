#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "hashable.h"
#include "cloneable.h"
#include "linkedmap.h"

class Person: public Cloneable {
    private:
        string name;
        int age;
    public:
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        int getAge() {
            return age;
        }
        Cloneable* clone() {
            return new Person(name, age);
        }
};

int main() {
    Map* m = new LinkedMap();
    HashableString name1("chris");
    Person p1("chris", 31);
    m->put(&name1, &p1);

    HashableString name2("celia");
    Person p2("celia", 31);
    m->put(&name2, &p2);

    HashableString name3("james");
    Person p3("james", 24);
    m->put(&name3, &p3);
    
    // Make sure the map contains a key with the string "chris"
    HashableString chris("chris");
    cout << m->containsKey(&chris) << endl;
    // Get the value associated to "chris" and print out the age
    Person* p = (Person*) m->get(&chris);
    cout << p->getAge() << endl;
    // Remove "chris," and make sure it's no longer in the map
    m->remove(&chris);
    cout << m->containsKey(&name1) << endl;

    delete m;
    return 0;
}