# Process Management Simulator
**Author:** Vandan Amin 

**Date:** May 9th, 2025

## Introduction
The program demonstrates basic process management in a Unix-like operating system. It shows how a parent process can create multiple child processes, have each child run a different command, and wait for all the child processes to complete before finishing itself.
The implementation uses key system calls like `fork()`, `execvp()`, and `wait()` to manage the behavior of processes.

## Implementation Summary
The program defines an array of simple Linux commands.
Using a loop, the parent process calls `fork()` 10 times, once for each command.
Each child process prints its own process ID (PID) and the command it will execute.
It then uses `execvp()` to replace its memory space with the new command.
If `execvp()` fails, the child prints an error message and exits with a nonzero status.

The parent process uses `wait()` to wait for each child to terminate.  
When a child finishes, the parent prints the child's PID and reports whether the child exited normally or was terminated by a signal.

The commands executed by the child processes are all standard Linux utilities:
- `ls` – list directory contents
- `date` – show the current date and time
- `pwd` – print the working directory path
- `id` – display user ID and group ID information
- `uname` – print basic system information
- `who` – show currently logged-in users
- `df` – display available disk space
- `uptime` – show how long the system has been running
- `ps` – display current active processes
- `echo "Hello Vandan"` – output a custom greeting (required for the assignment)

A simple Makefile is used to compile the program and clean up compiled files with `make` and `make clean`.

## Results and Observations

### A. Process Creation and Management
Each `fork()` call successfully created a child process.  
Inside the child, `execvp()` replaced the process with the specified command, demonstrating how a process can be fully replaced by a new program.  
If a command could not be executed, the error was printed, and the child process exited with a nonzero exit code.

### B. Parent and Child Interaction
The parent process waited for each child using `wait()`.  
For each completed child, the parent printed the process ID and whether the child exited normally or was terminated by a signal.  
All child processes exited normally with status 0, indicating successful execution.

The output of different commands sometimes appeared interleaved.  
This behavior is expected because multiple child processes run concurrently, and their outputs to the console may overlap depending on the operating system’s scheduling.

### C. Use of `execvp`
The `execvp()` function was used because it automatically searches the system's PATH environment variable for the specified command.  
This approach made it easier to run common commands like `ls` and `date` without needing to specify full file paths.

### D. Error Handling
Error handling was included for both `fork()` and `execvp()`:
- If `fork()` failed, an error message was printed, and the program exited.
- If `execvp()` failed, the child printed an error message and exited with a nonzero code.

This allowed the parent process to continue managing other child processes correctly even if one failed.

## Conclusion
The program shows how to create and manage multiple child processes in a Unix-like environment using `fork()`, `execvp()`, and `wait()`.  
It demonstrates how processes can be replaced by new programs and how a parent can track the termination of all its child processes.  
The behavior observed during execution, including concurrent output and proper synchronization, reflects how real multitasking works inside an operating system.
