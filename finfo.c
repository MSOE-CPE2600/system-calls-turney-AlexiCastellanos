/*************************************************************************
* Name: Alexi Castellanos
* Filename: finfo.c
* CPE 2600: Lab 9 - System Calls
* Date: 11/15/24
***********************************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error retrieving file information");
        return 1;
    }

    // File type
    if (S_ISREG(file_stat.st_mode)) printf("Type: Regular file\n");
    if (S_ISDIR(file_stat.st_mode)) printf("Type: Directory\n");

    // Permissions
    printf("Permissions: ");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");

    // File owner
    struct passwd* pwd = getpwuid(file_stat.st_uid);
    if (pwd != NULL) {
        printf("Owner: %s (UID: %d)\n", pwd->pw_name, file_stat.st_uid);
    } else {
        printf("Owner: UID %d\n", file_stat.st_uid);
    }

    // File size
    printf("Size: %ld bytes\n", file_stat.st_size);

    // Last modification time
    char time_buffer[80];
    struct tm* time_info = localtime(&file_stat.st_mtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Last modified: %s\n", time_buffer);

    return 0;
}
