MATLABROOT=/usr/local/MATLAB/R2011b
CC=g++
CFLAGS=-g -Wall

all: laser_reader

test: setup.cpp
	g++ -I${MATLABROOT}/extern/include -L${MATLABROOT}/extern/lib -llibeng -llibmat -llibmx setup.cpp -o setup

laser_reader: laser_reader.cpp
	g++ -I/usr/include/player-2.0 -L/usr/lib laser_reader.cpp -lplayerc++ -o laser_reader

clean:
	rm -f *.txt *~ *.o laser_reader
