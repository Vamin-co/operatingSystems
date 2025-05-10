#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process
        printf("Child: PID = %d\n", getpid());

        // Create source and destination folders
        system("mkdir -p source_folder des_folder");

        // Create two empty files in the source folder
        system("touch source_folder/file1.txt source_folder/file2.txt");

        // Set up cp -r source_folder des_folder
        char *args[] = {"cp", "-r", "source_folder", "des_folder", NULL};

        printf("Copying files...\n");

        // Execute the cp command
        execvp("cp", args);

        // If execvp fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent: PID = %d, spawned child PID = %d\n", getpid(), pid);

        // Wait for child to finish
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Child process completed successfully.\n");
        } else {
            printf("Child process failed or exited abnormally.\n");
        }
    }

    return 0;
}
