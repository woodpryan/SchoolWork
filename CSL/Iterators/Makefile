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
EXES=stl_iterator_ex stl_iterator_ex2 stl_const_iterator stl_auto

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

all: 	$(EXES)

stl_iterator_ex: stl_iterator_ex.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_iterator_ex2: stl_iterator_ex2.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_const_iterator: stl_const_iterator.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

stl_auto: stl_auto.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	-rm *.o
	-rm $(EXES)


