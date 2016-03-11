#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
   // Initialize the MPI environment
   MPI_Init(NULL, NULL);
  
   // Get the number of processes
   int world_size;
   MPI_Comm_size(MPI_COMM_WORLD, &world_size);

   // Get the rank of the process
   int world_rank;
   MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

   // Get the name of the processor
   char processor_name[MPI_MAX_PROCESSOR_NAME];
   int name_len;
   MPI_Get_processor_name(processor_name, &name_len);

   int max_threads = omp_get_max_threads(); 

   if (world_rank == 0) {
      printf("Total number of MPI processes: %d\n", world_size);
      printf("\nHost\tRank\tMax OpenMP threads\n");
   }

   MPI_Barrier(MPI_COMM_WORLD);

   printf("%s\t%d\t%d\n", processor_name, world_rank, max_threads);

   MPI_Barrier(MPI_COMM_WORLD);

   if (world_rank == 0) {
      printf("\nSpawning threads\n\n");
      printf("Host\tRank\tThread\n");
   }

   MPI_Barrier(MPI_COMM_WORLD);

#pragma omp parallel 
  printf("%s\t%d\t%d/%d\n", processor_name, world_rank, omp_get_thread_num(), max_threads);
  
  // Finalize the MPI environment.
  MPI_Finalize();
}
