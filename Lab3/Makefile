# Makefile for CPU Scheduling Simulator
CC = gcc
CFLAGS = -Wall -O2

all: sjf rr

sjf: SJF_inital.c
	$(CC) $(CFLAGS) -o sjf SJF_inital.c

rr: RR_inital.c
	$(CC) $(CFLAGS) -o rr RR_inital.c

clean:
	rm -f sjf rr
