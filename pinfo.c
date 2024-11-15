// pinfo.c
// Name: Alexi Castellanos
// Assignment: Lab 9 - System Calls
// Section: CPE 2600

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

const char* get_scheduler_name(int scheduler) {
    switch (scheduler) {
        case SCHED_OTHER: return "SCHED_OTHER (Normal)";
        case SCHED_FIFO:  return "SCHED_FIFO (Real-Time, First-In-First-Out)";
        case SCHED_RR:    return "SCHED_RR (Real-Time, Round Robin)";
        case SCHED_BATCH: return "SCHED_BATCH (Batch Processing)";
        case SCHED_IDLE:  return "SCHED_IDLE (Low Priority)";
#ifdef SCHED_DEADLINE
        case SCHED_DEADLINE: return "SCHED_DEADLINE (Deadline Scheduler)";
#endif
        default: return "Unknown Scheduling Method";
    }
}

int main(int argc, char *argv[]) {
    pid_t pid;
    int priority;
    int scheduler;

    // Determine if a process ID was provided as a command-line argument
    if (argc > 1) {
        pid = atoi(argv[1]);
        if (pid <= 0) {
            fprintf(stderr, "Error: Invalid process ID '%s'\n", argv[1]);
            return 1;
        }
    } else {
        pid = getpid(); // Default to current process
    }

    printf("Retrieving information for process ID: %d\n", pid);

    // Get process priority
    errno = 0; // Clear errno before calling getpriority
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("Error getting process priority");
        return 1;
    }
    printf("Process priority: %d\n", priority);

    // Get scheduling method
    scheduler = sched_getscheduler(pid);
    if (scheduler == -1) {
        perror("Error getting scheduler");
        return 1;
    }
    printf("Scheduling method: %s\n", get_scheduler_name(scheduler));

    return 0;
}
