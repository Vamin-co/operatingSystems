#ifndef VANDAN_LIBFS_H
#define VANDAN_LIBFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 4096

// Struct for file metadata (for in-memory simulation)
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
    int isOpen;
    int fd;
} File;

int fileCreate(const char* filename);
int fileOpen(const char* filename);
int fileWrite(int fd, const char* data);
int fileRead(int fd, char* buffer, int length);
int fileClose(int fd);
int fileDelete(const char* filename);

#endif 
