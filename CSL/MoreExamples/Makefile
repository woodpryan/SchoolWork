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
EXES=vectordemo lists maps maps_strings maps_class_value maps_class_key multimap

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all:	$(EXES)

vectordemo:  vectordemo.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

lists:	lists.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

maps:	maps.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

maps_strings:	maps_strings.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

maps_class_value:	maps_class_value.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

maps_class_key:	maps_class_key.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

multimap:	multimap.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm *.o
	rm $(EXES)
