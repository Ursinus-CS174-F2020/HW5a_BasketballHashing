#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "hashable.h"
#include "cloneable.h"
#include "hashtable.h"
#include "linkedmap.h"

using namespace std;

class Player: public Cloneable {
    public:
        string name;
        string school;
        int height;
        int weight;
        int year;
        Player(string name, string school, int height, int weight, int year) {
            this->name = name;
            this->school = school;
            this->height = height;
            this->weight = weight;
            this->year = year;
        }
        Cloneable* clone() {
            return new Player(name, school, height, weight, year);
        }
};

/**
 * Populate a map with all of the basketball players in the file 
 * "players.txt"
 * @param map A map to fill
 */
void loadPlayers(Map* map) {
    // TODO: Fill this in.  Load in each player and put
    // them in the map with a HashableString with their name
    // as the key and a player as their value.  Look at Person.cpp
    // for an example of how to put things into a map
    ifstream file("players.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)) {
            
        }
    }
    // TODO: To make sure this works properly, you might want to check that 
    // the map contains "Allen Iverson" and "Charles Barkley" but that it does 
    // not contain your name (unless I missed a big fun fact about you!),
    // by using the containsKey() method.  You might also want to simply
    // print out the name of each player to make sure the keys are right
}


void compareMaps() {
    // TODO: Fill this in
    // 1. Create a map m1 of type LinkedMap and a map m2 of type HashMap
    // and fill them with the players.
    // 2. Reset the operation counts of each map
    // 3. Loop through all of the keys in m1 and make sure they're in m2
    //    by calling the containsKey() method.  If they're not, print out
    //    the ones that are missing to help you debug
    // 4. Loop through all of the keys in m2 and make sure they're in m1
    //    by calling the containsKey() method.  If they're not, print out
    //    the ones that are missing to help you debug
    // 5. Report the number of operations in steps 3 and 4, and the average
    //    number of operations per player
}


int main() {
    compareMaps();
    return 0;
}
