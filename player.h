#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "hashable.h"
#include "cloneable.h"
#include "hashtable.h"
#include "linkedmap.h"

class Player: public Cloneable {
    private:
        string name;
        string school;
        int height;
        int weight;
        int year;
    public:
        Player(string name, string school, int height, int weight, int year);
        Cloneable* clone();
        void printPlayer();
};

/**
 * Populate a map with all of the basketball players in the file 
 * "players.txt"
 * @param map A map to fill
 */
void loadPlayers(Map* map);

#endif