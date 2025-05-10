#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *commands[][3] = {
        {"ls", NULL, NULL},
        {"date", NULL, NULL},
        {"pwd", NULL, NULL},
        {"echo", "Hello Vandan", NULL},
        {"id", NULL, NULL},
        {"uname", NULL, NULL},
        {"who", NULL, NULL},
        {"df", NULL, NULL},
        {"uptime", NULL, NULL},
        {"ps", NULL, NULL}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            printf("Child PID %d: executing %s\n", getpid(), commands[i][0]);
            execvp(commands[i][0], commands[i]);
            perror("execvp failed");
            exit(1);
        }
    }

    // Parent process waits
    for (int i = 0; i < num_commands; i++) {
        int status;
        pid_t pid = wait(&status);
        if (pid > 0) {
            if (WIFEXITED(status)) {
                printf("Child PID %d exited with status %d\n", pid, WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child PID %d killed by signal %d\n", pid, WTERMSIG(status));
            }
        }
    }

    printf("Parent process: all children have completed.\n");
    return 0;
}
