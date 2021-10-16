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
EXES=abssort findif higher templates

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

all:	$(EXES)

abssort: abssort.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

findif: findif.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

higher: higher.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

templates: templates.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm *.o
	rm $(EXES)



