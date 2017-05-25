#include <mpi.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
  clock_t begin, end;

  // Initialize the MPI environment
  begin = clock();
  MPI_Init(&argc, &argv);
  printf("MPI_Init time: %Lf\n", (long double) (clock() - begin) / CLOCKS_PER_SEC);

  // Get the number of processes
  int world_size;
  begin = clock();
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  printf("MPI_Comm_size time: %Lf\n", (long double) (clock() - begin) / CLOCKS_PER_SEC);
  
  // Get the rank of the process
  int world_rank;
  begin = clock();
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  printf("MPI_Comm_rank time: %Lf\n", (long double) (clock() - begin) / CLOCKS_PER_SEC);

  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  // Print off a hello world message
  if (world_rank == 0) {
    printf("Total number of MPI processes: %d\n", world_size);
  }

  printf("MPI rank %d on processor %s\n", world_rank, processor_name);

  // Finalize the MPI environment.
  MPI_Finalize();
}


