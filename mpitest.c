#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
        int rank, size;
        MPI_Comm comm;
        comm = MPI_COMM_WORLD;

        MPI_Init (&argc, &argv);
        char name[MPI_MAX_PROCESSOR_NAME];
        int resultlength;
        MPI_Get_processor_name(name, &resultlength);
        MPI_Comm_rank (comm, &rank);
        MPI_Comm_size (comm, &size);
        printf("Hello from rank %d o host %s\n", rank, name);
        MPI_Barrier(comm);
        MPI_Finalize();
}
