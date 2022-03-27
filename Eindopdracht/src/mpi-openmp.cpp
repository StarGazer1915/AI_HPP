#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <math.h>
#include <omp.h>
#include <mpi.h>

using std::cout, std::endl, std::cin, std::to_string ,std::vector;

int main(int argc, char *argv[]) 
{   
   unsigned long long n = 1000000000;
   vector<bool> table(n, true);
   int rank, comm_size;
   omp_set_num_threads(4);

   double startTime = 0.0, totalTime = 0.0;
   startTime = MPI_Wtime();

   unsigned long long max_n = sqrt(n);

   MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);   

   #pragma omp parallel for
   for (unsigned long long p = 2; p < max_n; p++) {
      if (p%comm_size != rank) continue;
      if (table[p] == true) {
         for (unsigned long long i = p * p; i < n; i += p)
            table[i] = false;
      }
   }
   
   MPI_Finalize();

   totalTime = MPI_Wtime() - startTime;
   cout << "\nProcess " << rank << " finished in " << totalTime << " seconds." << endl;
   
   // ===== Uncomment the code below to print all values in terminal =====
   // ===== NOTE: This might print confusing results if you're working with multiple MPI processes. =====
   // for (unsigned long long p = 2; p < n; p++) {
   //    if (table[p])
   //       cout << p << " ";
   // }
   // cout << "\n" << endl;

   return 0;
}
