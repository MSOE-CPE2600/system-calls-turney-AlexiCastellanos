/*************************************************************************
* Name: Alexi Castellanos
* Filename: pmod.c
* CPE 2600: Lab 9 - System Calls
* Date: 11/15/24
***********************************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h> 

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


    //Print goodbye message and exit
    printf("goodbye, exiting program.\n");

    return 0; // Exit successfully
}
