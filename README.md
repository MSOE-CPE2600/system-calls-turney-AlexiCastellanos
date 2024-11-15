# Lab 9 - System Calls

## Overview
This project contains four separate programs written in C. Each program demonstrates the use of various POSIX system calls to interact with system information, process control, and file management.

### Programs
1. **info.c** - Displays system information such as current time, network name, OS version, number of CPUs, and memory details.
2. **pinfo.c** - Retrieves and displays process information, including priority and scheduling method, for a specified PID (or the current process if no PID is provided).
3. **pmod.c** - Modifies its own priority, sleeps for a specified time, and then exits with a goodbye message.
4. **finfo.c** - Displays detailed file information for a specified file, including file type, permissions, owner, size, and last modification time.

## Files
- `info.c` - Source code for the system information program.
- `pinfo.c` - Source code for the process information program.
- `pmod.c` - Source code for the process modification and sleep program.
- `finfo.c` - Source code for the file information program.
- `Makefile` - Automates the compilation and cleanup of the project.
- `README.md` - Project documentation.

## Compilation
To compile all programs at once, use the following command:
make
make info
make pinfo
make pmod
make finfo

## Usage
- info - displays system information: 
        ./info
- pinfo - Displays process information for given PID, if no PID is provided, the current process is used: 
        ./pinfo <pid>
- pmod - modifies priority,sleeps, and prints goodbye message: 
        ./pmod
- finfo - displays inforamtion for a specified file, Requires a filename as an argument:
        ./finfo <filename>


## Cleaning up
make clean

## Notes
- Requirements: These programs should be run on a POSIX-complaint system (Linux) as they use POSIX system calls
- Error Handling: Each Program includes basic error handling to display informative messages if something goes wrong.

## Debugging
Use 'gdb' for debugging or 'valgrind' to check for any runtime errors and memory leaks :
gdb ./info
valgrind ./pinfo <pid>


### Explanation

- **Overview and Program Descriptions**: Provides a summary of the project and each program’s purpose.
- **Compilation Instructions**: Explains how to use the `Makefile` to compile all or individual programs.
- **Usage**: Describes how to run each program, including required arguments.
- **Cleaning Up**: Instructions on removing executables using `make clean`.
- **Notes**: Important information about running the programs on a POSIX system and handling errors.
- **Debugging**: Tips for using `gdb` and `valgrind`.
- **Submission Instructions**: Reminds to tag the final commit and push to GitHub.



