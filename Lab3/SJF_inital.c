#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int is_completed;
} Process;

int n; // Number of processes

// Function to find the index of the process with the shortest remaining time
int findNextProcess(Process proc[], int current_time) {
    int idx = -1;
    int min_remaining_time = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (proc[i].arrival_time <= current_time &&
            !proc[i].is_completed &&
            proc[i].remaining_time < min_remaining_time &&
            proc[i].remaining_time > 0) {
            min_remaining_time = proc[i].remaining_time;
            idx = i;
        }
    }

    return idx;
}

// Function to perform the SRTF scheduling
void srtf(Process proc[]) {
    int completed = 0;
    int current_time = 0;
    int execution_order[1000];
    int exec_index = 0;

    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
        proc[i].is_completed = 0;
    }

    while (completed != n) {
        int idx = findNextProcess(proc, current_time);

        if (idx != -1) {
            execution_order[exec_index++] = proc[idx].process_id;
            proc[idx].remaining_time--;

            if (proc[idx].remaining_time == 0) {
                proc[idx].is_completed = 1;
                completed++;
                int finish_time = current_time + 1;
                proc[idx].turnaround_time = finish_time - proc[idx].arrival_time;
                proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].burst_time;
                if (proc[idx].waiting_time < 0) proc[idx].waiting_time = 0;
            }
        } else {
            execution_order[exec_index++] = -1; // idle time
        }

        current_time++;
    }

    // Print execution order
    printf("\nExecution Order:\n");
    for (int i = 0; i < exec_index; i++) {
        if (execution_order[i] == -1)
            printf("Idle ");
        else
            printf("P%d ", execution_order[i]);
    }
    printf("\n");
}

// Function to print the processes and their details
void printProcesses(Process proc[]) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    // Calculate average times
    float total_wt = 0, total_tt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting_time;
        total_tt += proc[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tt / n);
}

int main() {
    // Initialize processes with their IDs, arrival times, and burst times
    Process proc[] = {{1, 0, 8}, {2, 1, 4}, {3, 2, 9}, {4, 3, 5}};
    n = sizeof(proc) / sizeof(proc[0]);

    srtf(proc);
    printProcesses(proc);

    return 0;
}
