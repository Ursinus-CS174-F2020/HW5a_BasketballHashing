CC=g++
CFLAGS=-std=c++11 -g -Wall 


hashable.o: hashable.cpp hashable.h
	$(CC) $(CFLAGS) -c hashable.cpp 
	
hashtable.o: hashtable.h hashtable.cpp hashable.o map.h
	$(CC) $(CFLAGS) -c hashtable.cpp 

linkedmap.o: linkedmap.h linkedmap.cpp hashable.o map.h
	$(CC) $(CFLAGS) -c linkedmap.cpp 

player: hashable.o linkedmap.o player.cpp
	$(CC) $(CFLAGS) -o player hashable.o linkedmap.o player.cpp

clean:
	rm *.o