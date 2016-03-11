# omp-mpi-tests
Small tests to make sure that OpenMP and MPI are working


# How to build

```bash
mkdir build
cd build
cmake ..
make
```

# Testing

```
./omp/test_omp 
./mpi/test_mpi 
./mpi_omp/test_mpi_omp 

mpirun -np 1 ./mpi/test_mpi
mpirun -np 1 ./mpi/test_mpi_omp
```

# Why these tests exist

I was noticing slowness for some of my MPI runs and some debugging showed that only
2 threads were being created on an 8 core machine with hyperthreading. To understand
the problem, I created these small tests to make sure that something wasn't misconfigured
on the machine.

Here's an example of that output:

```
mpirun -np 1 ./mpi_omp/test_mpi_omp 

Total number of MPI processes: 1

Host		Rank	Max OpenMP threads
abcd	0		2

Spawning threads
Host		Rank	Thread
abcd	0		1/2
abcd	0		0/2
```

I expected Max OpenMP threads to be 16. Changing the command line to:

```
mpirun -np 1 --bind-to none ./mpi_omp/test_mpi_omp 
```

Resulted in:

```
Total number of MPI processes: 1

Host	Rank	Max OpenMP threads
abcd	0	16

Spawning threads
Host	Rank	Thread
abcd	0	10/16
abcd	0	3/16
abcd	0	0/16
abcd	0	6/16
abcd	0	8/16
abcd	0	13/16
abcd	0	1/16
abcd	0	15/16
abcd	0	14/16
abcd	0	12/16
abcd	0	11/16
abcd	0	2/16
abcd	0	7/16
abcd	0	4/16
abcd	0	9/16
abcd	0	5/16
```
