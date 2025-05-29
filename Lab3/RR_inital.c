#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to calculate waiting times and execution order for all processes
void calculateWaitingTimeAndExecutionOrder(Process proc[], int n, int quantum) {
    int time = 0, completed = 0;
    int *is_done = (int *)calloc(n, sizeof(int));
    int *start_time = (int *)calloc(n, sizeof(int));
    bool *started = (bool *)calloc(n, sizeof(bool));
    int i;
    printf("Execution order: ");

    while (completed < n) {
        bool all_idle = true;

        for (i = 0; i < n; i++) {
            if (proc[i].arrival_time <= time && proc[i].remaining_time > 0) {
                all_idle = false;

                if (!started[i]) {
                    start_time[i] = time;
                    started[i] = true;
                }

                int run_time = (proc[i].remaining_time > quantum) ? quantum : proc[i].remaining_time;
                printf("P%d ", proc[i].process_id);
                time += run_time;
                proc[i].remaining_time -= run_time;

                if (proc[i].remaining_time == 0) {
                    completed++;
                    proc[i].waiting_time = time - proc[i].arrival_time - proc[i].burst_time;
                    if (proc[i].waiting_time < 0) proc[i].waiting_time = 0;
                }
            }
        }

        if (all_idle)
            time++; // If CPU is idle, move time forward
    }

    free(is_done);
    free(start_time);
    free(started);
    printf("\n");
}

// Function to calculate turnaround times for all processes
void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void roundRobin(Process proc[], int n, int quantum) {
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
    }
    calculateWaitingTimeAndExecutionOrder(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
}

void printProcesses(Process proc[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    float avg_wait = 0, avg_turnaround = 0;
    for (int i = 0; i < n; i++) {
        avg_wait += proc[i].waiting_time;
        avg_turnaround += proc[i].turnaround_time;
    }

    avg_wait /= n;
    avg_turnaround /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
}

int main() {
    Process proc[] = {{1, 0, 24}, {2, 0, 3}, {3, 0, 3}};
    int n = sizeof(proc) / sizeof(proc[0]); // Number of processes
    int quantum = 4; // Time quantum for Round Robin scheduling
    if (quantum < 1){
        printf("Please use quantum time that is at least greater than or equal to 1.\n");
        return 0;
    }
    roundRobin(proc, n, quantum);
    printProcesses(proc, n);

    return 0;
}
