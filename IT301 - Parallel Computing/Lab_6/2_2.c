#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int size, myrank;
    MPI_Status status;
    char message[6]; // "PCLAB" + null terminator

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
        strcpy(message, "PCLAB");
        printf("Process %d of %d sending message: %s\n", myrank, size, message);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 55, MPI_COMM_WORLD);
    } else if (myrank == 1) {
        MPI_Recv(message, 6, MPI_CHAR, 0, 55, MPI_COMM_WORLD, &status);
        printf("Process %d of %d received message: %s\n", myrank, size, message);
        printf("Source %d Tag %d\n", status.MPI_SOURCE, status.MPI_TAG);
    }

    MPI_Finalize();
    return 0;
}
