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
// Main function to retrieve and display file information.
int main(int argc, char* argv[]) {
    // Ensure the correct number of arguments is provided.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;  // Exit with error if no file name is provided.
    }

    struct stat file_stat;

    // Retrieve file information using stat(). Exit if stat fails.
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error retrieving file information");
        return 1;  // Exit with error if the file cannot be accessed.
    }

    // Determine and display the file type.
    if (S_ISREG(file_stat.st_mode)) {
        printf("Type: Regular file\n");
    }
    if (S_ISDIR(file_stat.st_mode)) {
        printf("Type: Directory\n");
    }

    // Display file permissions for the owner (read, write, execute).
    printf("Permissions: ");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");

    // Retrieve and display the file owner (username if available).
    struct passwd* pwd = getpwuid(file_stat.st_uid);
    if (pwd != NULL) {
        printf("Owner: %s (UID: %d)\n", pwd->pw_name, file_stat.st_uid);
    } else {
        printf("Owner: UID %d\n", file_stat.st_uid);
    }

    // Display the file size in bytes.
    printf("Size: %ld bytes\n", file_stat.st_size);

    // Retrieve and display the last modification time in a readable format.
    char time_buffer[80];
    struct tm* time_info = localtime(&file_stat.st_mtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Last modified: %s\n", time_buffer);

    return 0;  // Exit successfully.
}
