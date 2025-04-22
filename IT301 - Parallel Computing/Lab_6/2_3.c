#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int size, myrank;
    MPI_Status status;
    int array[5] = {1, 2, 3, 4, 5}; // Array to send

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
        printf("Process %d of %d sending array: ", myrank, size);
        for (int i = 0; i < 5; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        MPI_Send(array, 5, MPI_INT, 1, 55, MPI_COMM_WORLD);
    } else if (myrank == 1) {
        int recv_array[5];
        MPI_Recv(recv_array, 5, MPI_INT, 0, 55, MPI_COMM_WORLD, &status);
        printf("Process %d of %d received array: ", myrank, size);
        for (int i = 0; i < 5; i++) {
            printf("%d ", recv_array[i]);
        }
        printf("\n");
        printf("Source %d Tag %d\n", status.MPI_SOURCE, status.MPI_TAG);
    }

    MPI_Finalize();
    return 0;
}
