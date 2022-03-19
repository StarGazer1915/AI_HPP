/* arraySum.cpp uses an array to sum the values in an input file,
 * whose name is specified on the command-line.
 */
#include <iostream>
#include <fstream>
#include <omp.h> // OpenMP
#include <thread>
#include <vector>

using std::cout, std::endl, std::thread, std::vector;

void readArray(char *fileName, double **a, int *n);
double sumArray(double *a, int numValues);

int main(int argc, char *argv[], int num_of_threads)
{
    int howMany;
    double sum;
    double *a;
    omp_set_num_threads(num_of_threads);
    double start = omp_get_wtime();

    if (argc != 2)
    {
        cout << endl << "*** Usage: arraySum <inputFile>" << endl << endl;
        exit(1);
    }

    

    #pragma omp master
    {
        // vector<vector<int>> sliced_vector = slice_vector(&a, 4);
        #pragma omp parallel for
        
        sum = sumArray(a, howMany);
        cout << "The sum of the values in the input file '" << argv[1] << "' is " << sum << endl;



    }
    
    
    double end = omp_get_wtime();
    cout << "Elasped time = " << (end - start) << " sec" << endl;
    
    free(a);
    return 0;
}

vector<vector<int>> slice_vector(vector<int> xs, int num_of_threads) {
    /*
    Divides a vector into slices/parts for each thread.
    So the vector will be split into four subvectors should the num_of_threads be 4.
    */
    int part = xs.size() / num_of_threads;
    vector<vector<int>> sliced_vector;

    for (int slice = 0 ; slice < xs.size() ; slice += part) {
        vector<int> v_part(xs.begin() + slice, xs.begin() + slice + part);
        sliced_vector.push_back(v_part);
    }
    return sliced_vector;
}

/* readArray fills an array with values from a file.
 * Receive: fileName, a char*,
 *          a, the address of a pointer to an array,
 *          n, the address of an int.
 * PRE: fileName contains N, followed by N double values.
 * POST: a points to a dynamically allocated array
 *        containing the N values from fileName
 *        and n == N.
 */

void readArray(char *fileName, double **a, int *n)
{
    int count, howMany;
    double *tempA;
    std::ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << endl << "*** Unable to open input file '" << fileName << "'" << endl << endl;
        exit(1);
    }

    fin >> howMany;
    tempA = (double *)calloc(howMany, sizeof(double));
    if (tempA == NULL)
    {
        cout << endl << "*** Unable to allocate " << howMany << "-length array" << endl << endl;
        exit(1);
    }

    for (count = 0; count < howMany; count++)
        fin >> tempA[count];

    fin.close();

    *n = howMany;
    *a = tempA;
}

/* sumArray sums the values in an array of doubles.
 * Receive: a, a pointer to the head of an array;
 *          numValues, the number of values in the array.
 * Return: the sum of the values in the array.
 */

double sumArray(double *a, int numValues)
{
    int i;
    double result = 0.0;

    for (i = 0; i < numValues; i++)
    {
        result += a[i];
    }

    return result;
}
