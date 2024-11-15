
// info.c
// Name: Alexi Castellanos
// Assignment: Lab 9 - System Calls

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct timespec ts;         // Structure to hold time information
    struct utsname uname_data;  // Structure to hold system information
    struct sysinfo sys_info;    // Structure to hold memory information

    // Get the current time in seconds and nanoseconds since the Epoch
    if (clock_gettime(CLOCK_REALTIME, &ts) == 0) {
        printf("Current time: %ld seconds, %ld nanoseconds\n", ts.tv_sec, ts.tv_nsec);
    } else {
        perror("Error retrieving time");
    }

    // Get system information: network name, OS name, release, version, and hardware type
    if (uname(&uname_data) == 0) {
        printf("Network name: %s\n", uname_data.nodename);
        printf("Operating system: %s\n", uname_data.sysname);
        printf("OS release: %s\n", uname_data.release);
        printf("OS version: %s\n", uname_data.version);
        printf("Hardware type: %s\n", uname_data.machine);
    } else {
        perror("Error retrieving system information");
    }

    // Get the number of CPUs available on the system
    long num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_cpus != -1) {
        printf("Number of CPUs: %ld\n", num_cpus);
    } else {
        perror("Error retrieving number of CPUs");
    }

    // Get memory information (total and free memory in bytes)
    if (sysinfo(&sys_info) == 0) {
        printf("Total memory: %lu bytes\n", sys_info.totalram);
        printf("Free memory: %lu bytes\n", sys_info.freeram);
    } else {
        perror("Error retrieving memory information");
    }

    return 0;
}


