CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: playerlookup mapcheck person

hashable.o: hashable.cpp hashable.h
	$(CC) $(CFLAGS) -c hashable.cpp 
	
hashtable.o: hashtable.h hashtable.cpp hashable.o map.h
	$(CC) $(CFLAGS) -c hashtable.cpp 

linkedmap.o: linkedmap.h linkedmap.cpp hashable.o map.h
	$(CC) $(CFLAGS) -c linkedmap.cpp 

player.o: hashable.o linkedmap.o hashtable.o player.cpp player.h
	$(CC) $(CFLAGS) -c player.cpp

playerlookup: hashable.o linkedmap.o hashtable.o player.o playerlookup.cpp
	$(CC) $(CFLAGS) -o playerlookup hashable.o linkedmap.o hashtable.o player.o playerlookup.cpp

mapcheck: hashable.o linkedmap.o hashtable.o player.o player.h mapcheck.cpp
	$(CC) $(CFLAGS) -o mapcheck hashable.o linkedmap.o hashtable.o player.o mapcheck.cpp

person: hashable.o linkedmap.o hashtable.o person.cpp
	$(CC) $(CFLAGS) -o person hashable.o linkedmap.o hashtable.o person.cpp

clean:
	rm *.o *.exe *.stackdump playerlookup mapcheck person