#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "hashable.h"
#include "cloneable.h"
#include "hashtable.h"
#include "linkedmap.h"
#include "player.h"


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
