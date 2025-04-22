#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    
    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

   
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    
    closedir(dir);
    return 0;
}
