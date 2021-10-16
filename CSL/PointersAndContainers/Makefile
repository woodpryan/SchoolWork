#
# File:    Makefile
# Author:  Adam.Lewis@athens.edu
# Purpose:
#          Build the examples for Module 02
# 
CC=g++
CFLAGS=-I. -std=c++14
LIBS=
DEPS= 
OBJ=
EXES=valref stl_vector stl_deque stl_tuple stl_map stl_multimap

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all:	$(EXES)

valref: valref.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_vector: stl_vector.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_deque: stl_deque.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_tuple: stl_tuple.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_map: stl_map.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_multimap: stl_multimap.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

clean:
	rm *.o
	rm $(EXES)



