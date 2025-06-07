#include "Vandan_libFS.h"

void showMenu() {
    printf("\n==== Vandan's libFS Test Menu ====\n");
    printf("1. Create File\n");
    printf("2. Open File\n");
    printf("3. Write Introduction\n");
    printf("4. Read File\n");
    printf("5. Close File\n");
    printf("6. Delete File\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char filename[100] = "Vandan_Introduction.txt";
    int fd = -1;
    int choice;
    char buffer[4096];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: {
                int result = fileCreate(filename);
                if (result == 0) printf("File created successfully.\n");
                else if (result == -2) printf("File already exists.\n");
                else printf("Failed to create file.\n");
                break;
            }

            case 2: {
                fd = fileOpen(filename);
                if (fd > 0) printf("File opened. File descriptor: %d\n", fd);
                else if (fd == -2) printf("File already open.\n");
                else printf("File not found.\n");
                break;
            }

            case 3: {
                if (fd <= 0) {
                    printf("Please open the file first.\n");
                    break;
                }
                const char* intro = 
                    "My name is Vandan Amin. I'm a student passionate about systems programming and backend development.\n"
                    "I enjoy learning how operating systems and file systems work at a low level.\n\n"
                    "This project helps me understand file system mechanics by simulating how files are created, accessed, and managed.\n"
                    "I look forward to building more advanced system-level software.\n";

                int written = fileWrite(fd, intro);
                if (written > 0) printf("Introduction written to file.\n");
                else printf("Failed to write to file.\n");
                break;
            }

            case 4: {
                if (fd <= 0) {
                    printf("Please open the file first.\n");
                    break;
                }
                int readLen = fileRead(fd, buffer, sizeof(buffer) - 1);
                if (readLen > 0) {
                    printf("\n--- File Contents ---\n%s\n", buffer);
                } else {
                    printf("Failed to read from file.\n");
                }
                break;
            }

            case 5: {
                if (fd <= 0) {
                    printf("No file is open.\n");
                    break;
                }
                if (fileClose(fd) == 0) {
                    printf("File closed successfully.\n");
                    fd = -1;
                } else {
                    printf("Failed to close file.\n");
                }
                break;
            }

            case 6: {
                int result = fileDelete(filename);
                if (result == 0) printf("File deleted successfully.\n");
                else if (result == -2) printf("File is currently open. Close it first.\n");
                else printf("Failed to delete file.\n");
                break;
            }

            case 7: {
                printf("Exiting program.\n");
                return 0;
            }

            default:
                printf("Invalid option.\n");
        }
    }
}
