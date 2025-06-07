#include "Vandan_libFS.h"

static File fileTable[MAX_FILES];
static int fileCount = 0;
static int nextFD = 1;

// Helper: find file index by filename
static int findFileIndex(const char* filename) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileTable[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

int fileCreate(const char* filename) {
    if (fileCount >= MAX_FILES) return -1;
    if (findFileIndex(filename) != -1) return -2;  // Already exists

    File newFile;
    strncpy(newFile.filename, filename, MAX_FILENAME_LENGTH);
    newFile.size = 0;
    newFile.isOpen = 0;
    newFile.fd = 0;

    fileTable[fileCount++] = newFile;
    return 0;
}

int fileOpen(const char* filename) {
    int index = findFileIndex(filename);
    if (index == -1) return -1;

    if (fileTable[index].isOpen) return -2;  // Already open

    fileTable[index].isOpen = 1;
    fileTable[index].fd = nextFD++;
    return fileTable[index].fd;
}

int fileWrite(int fd, const char* data) {
    for (int i = 0; i < fileCount; i++) {
        if (fileTable[i].fd == fd && fileTable[i].isOpen) {
            int dataLen = strlen(data);
            if (fileTable[i].size + dataLen > MAX_FILE_SIZE) return -2;

            strcat(fileTable[i].data, data);
            fileTable[i].size += dataLen;
            return dataLen;
        }
    }
    return -1;
}

int fileRead(int fd, char* buffer, int length) {
    for (int i = 0; i < fileCount; i++) {
        if (fileTable[i].fd == fd && fileTable[i].isOpen) {
            strncpy(buffer, fileTable[i].data, length);
            buffer[length] = '\0';
            return strlen(buffer);
        }
    }
    return -1;
}

int fileClose(int fd) {
    for (int i = 0; i < fileCount; i++) {
        if (fileTable[i].fd == fd) {
            fileTable[i].isOpen = 0;
            fileTable[i].fd = 0;
            return 0;
        }
    }
    return -1;
}

int fileDelete(const char* filename) {
    int index = findFileIndex(filename);
    if (index == -1) return -1;
    if (fileTable[index].isOpen) return -2;

    for (int i = index; i < fileCount - 1; i++) {
        fileTable[i] = fileTable[i + 1];
    }
    fileCount--;
    return 0;
}
