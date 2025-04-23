# Shell Script Automation Report

## Project Overview
This project focuses on learning basic shell scripting in Linux. The goal was to write a script that:
- Creates a main directory with the current date and time as its name.
- Makes ten subdirectories inside it (named `file101` to `file110`).
- In each subdirectory, creates a `.txt` file with a unique programming language name written in it.

The purpose is to practice working with Linux commands like `mkdir`, `echo`, and `date`, and get familiar with directory and file manipulation.

---

## How the Script Works

The shell script (`create_files_with_subdirs.sh`) does the following:

1. **Creates a main folder** using the current date and time. For example, `2025-04-23_14-45-32`.
2. **Defines an array** of ten programming languages (like Python, Java, etc.).
3. **Loops through a range** from 101 to 110 to:
   - Create a subfolder named `file101` to `file110`.
   - Create a file inside each subfolder, like `tuser501.txt` to `tuser510.txt`.
   - Write the matching programming language into that file (based on the loop count).

---

## Command Descriptions and Examples

| **Command** | **Description** | **Example Usage** |
|-------------|------------------|--------------------|
| `cp` | Copies files or directories | `cp file1.txt backup/` |
| `ps` | Shows current running processes | `ps aux` |
| `ls` | Lists files and directories | `ls -l` |
| `mv` | Moves or renames files | `mv oldname.txt newname.txt` |
| `rm` | Deletes files or directories | `rm file.txt` |
| `mkdir` | Makes a new directory | `mkdir my_folder` |
| `rmdir` | Removes an empty directory | `rmdir old_folder` |
| `echo` | Prints text to the terminal or a file | `echo "Hello World" > file.txt` |
| `more` | Views file content one page at a time | `more longfile.txt` |
| `date` | Shows current date and time | `date +"%Y-%m-%d_%H-%M-%S"` |
| `time` | Measures how long a command takes | `time ls` |
| `kill` | Ends a running process | `kill 1234` (where 1234 is the process ID) |
| `history` | Shows a list of previously run commands | `history` |
| `chmod` | Changes file permissions | `chmod +x script.sh` |
| `chown` | Changes file ownership | `sudo chown user:user file.txt` |

---

## Purpose of This Script
The goal of the script is to practice:
- Automating repetitive tasks
- Creating structured file systems
- Writing dynamic content using shell commands
- Understanding how to work with arrays, loops, and file redirection in bash
