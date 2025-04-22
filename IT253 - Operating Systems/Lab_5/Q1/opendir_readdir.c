#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    struct dirent *de;
    DIR *dr = opendir(argv[1]);

    if (dr == NULL) {
        printf("Could not open directory %s\n", argv[1]);
        return 1;
    }

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}
