# Makefile for Vandan's libFS Project

CC = gcc
CFLAGS = -Wall -g
TARGET = Vandan_testapp
OBJS = Vandan_testFS.o Vandan_libFS.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Vandan_testFS.o: Vandan_testFS.c Vandan_libFS.h
	$(CC) $(CFLAGS) -c Vandan_testFS.c

Vandan_libFS.o: Vandan_libFS.c Vandan_libFS.h
	$(CC) $(CFLAGS) -c Vandan_libFS.c

clean:
	rm -f *.o $(TARGET)
