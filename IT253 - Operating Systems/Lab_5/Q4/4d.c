#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sleeping for 5 seconds...\n");
    sleep(5); // Sleep for 5 seconds
    printf("Awake after sleeping!\n");
    return 0;
}
