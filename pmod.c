// Name, etc

// pmod.c
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h> // For strerror()

int main(int argc, char* argv[]) {
    // Step 1: Reduce process priority
    int priority_change = 10; // Amount to increase niceness
    int new_priority = nice(priority_change);

    // Check if nice() failed
    if (new_priority == -1) {
        // Print an error message without directly using errno
        fprintf(stderr, "Failed to change priority: %s\n", strerror(new_priority));
        return 1; // Exit with error code
    }

    printf("Priority successfully reduced by %d. Current niceness: %d\n", priority_change, new_priority);

    // Step 2: Sleep for 1,837,272,638 nanoseconds
    struct timespec ts;
    ts.tv_sec = 1;           // 1 second
    ts.tv_nsec = 837272638;  // 837,272,638 nanoseconds

    // Use nanosleep and handle errors
    int sleep_result = nanosleep(&ts, NULL);
    if (sleep_result < 0) {
        // Print an error message
        perror("Failed to sleep");
        return 1; // Exit with error code
    }

    printf("Slept for 1,837,272,638 nanoseconds.\n");

    // Step 3: Print goodbye message and exit
    printf("Goodbye! Exiting program.\n");

    return 0; // Exit successfully
}
