# Shell Script Automation Report
Name: Vandan Amin

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

---

## Linux Command Explanations

### `cp`
**Description:**  
Copies files or directories from one location to another.

**Example:**  
```bash
cp report.txt backup/
```
This command copies the file named `report.txt` into the `backup` folder.

---

### `ps`
**Description:**  
Shows the currently running processes on your system.

**Example:**  
```bash
ps aux
```
This command displays all running processes, including system and user processes, with detailed info like process ID (PID), CPU and memory usage.

---

### `ls`
**Description:**  
Lists all files and directories in the current location.

**Example:**  
```bash
ls -l
```
This command shows a detailed list (long format) of items in the current folder, including file size, permissions, and modification date.

---

### `mv`
**Description:**  
Moves or renames a file or directory.

**Example:**  
```bash
mv notes.txt archive/
```
This command moves the file `notes.txt` into the `archive` folder. You can also use `mv old.txt new.txt` to rename files.

---

### `rm`
**Description:**  
Deletes files or directories.

**Example:**  
```bash
rm old.txt
```
This removes the file named `old.txt`. To delete a folder and its contents, you can use `rm -r folder_name`.

---

### `mkdir`
**Description:**  
Creates a new directory.

**Example:**  
```bash
mkdir new_project
```
This makes a folder named `new_project` in the current directory.

---

### `rmdir`
**Description:**  
Removes a directory, but only if it’s empty.

**Example:**  
```bash
rmdir temp_folder
```
This deletes the folder `temp_folder`, but only if it contains no files or other directories.

---

### `echo`
**Description:**  
Prints text to the terminal or writes it to a file.

**Example:**  
```bash
echo "Welcome to Linux" > welcome.txt
```
This creates a file called `welcome.txt` and writes the text “Welcome to Linux” into it.

---

### `more`
**Description:**  
Displays the contents of a file one page at a time.

**Example:**  
```bash
more long_article.txt
```
This command shows the file content one screen at a time, helpful for reading long files.

---

### `date`
**Description:**  
Displays or sets the system date and time.

**Example:**  
```bash
date +"%Y-%m-%d_%H-%M-%S"
```
This prints the current date and time in a format like `2025-04-23_14-45-32`, useful for naming files or folders.

---

### `time`
**Description:**  
Measures how long a command takes to run.

**Example:**  
```bash
time ls -la
```
This command runs `ls -la` and then shows how long it took to execute (real, user, and sys times).

---

### `kill`
**Description:**  
Stops a running process using its process ID (PID).

**Example:**  
```bash
kill 2468
```
This command sends a signal to stop the process with PID `2468`. You can find the PID using `ps aux`.

---

### `history`
**Description:**  
Shows a list of previously entered commands in your terminal session.

**Example:**  
```bash
history
```
This prints your command history with line numbers, letting you re-run old commands easily.

---

### `chmod`
**Description:**  
Changes the permissions of a file or directory.

**Example:**  
```bash
chmod +x script.sh
```
This gives executable permission to the file `script.sh`, allowing it to be run as a program.

---

### `chown`
**Description:**  
Changes the ownership of a file or directory.

**Example:**  
```bash
sudo chown john:john data.txt
```
This command changes the owner of `data.txt` to the user `john`. Useful when working with permissions on shared files or system resources.

---

## Purpose of This Script
The goal of the script is to practice:
- Automating repetitive tasks
- Creating structured file systems
- Writing dynamic content using shell commands
- Understanding how to work with arrays, loops, and file redirection in bash
