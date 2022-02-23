#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <chrono>

using std::vector, std::to_string, std::cout, std::endl;
using namespace std::chrono;

vector<vector<double>> distributionPass(int indx, vector<int> n, vector<vector<double>> arr) {
    /*
    This function applies the distribution pass. The reason we change it to a double is because when we use 
    103 for example we get 1.03 which we then turn into an int again so we get 1. It will then take that 
    1 digit number and add it to the index vector in arr. (So if the digit is 4 then it will be placed in the 
    14th (4+10) vector. This is because we also work with negative numbers and the first 10 vectors are reserved 
    for those (-4 + 10 becomes 6 which we can use as index). After putting all the numbers in these "buckets" it then 
    returns the vector arr.
    */
    double exp = pow(10, indx+1);
    for(double num : n) {
        int first_num = (fmod(num, exp) / (exp / 10));
        arr[first_num + 10].push_back(num);
    }
    return arr;
}

vector<int> gatheringPass(vector<vector<double>> arr) {
    /*
    This function applies the gathering pass. It takes all the sorted values that have been placed
    in buckets and and places them back into a vector. After placing all numbers into the vector new_n it then returns it.
    */
    vector<int> new_n = {};
    for (vector<double> v : arr) {
        for (int num : v) {
            new_n.push_back(num);
        }
    }
    return new_n;
}

vector<int> bucketSort(vector<int> n) {
    /*
    This is the main bucketsort function. This is where the arr vector is defined and the longest number
    is determined (so that we know how long a number can really get inside the vector (max 9 numbers long)). 
    It then starts the for-loop that does the sorting. It then returns the now sorted vector.
    */
    vector<vector<double>> arr = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    double bigNumLen = to_string(*max_element(n.begin(), n.end())).length();
    
    for (int i = 0; i < bigNumLen ; i++) {
        n = gatheringPass(distributionPass(i, n, arr));
    }
    return n;
}

vector<int> random_vector(int seed, int num_of_rands) {
    /*
    This function returns a vector filled with random numbers based on the given seed and
    amount of numbers requested.
    */
    vector<int> randVector;
    srand(seed);
    for (int i = 0 ; i < num_of_rands ; i++) {
        randVector.push_back(rand());
    }
    return randVector;
}


int main() {
    /*
    The main function. An input vector is defined, then the bucketsort function is started and
    its output is shown.
    */

   // Creating the input vector for bucket sort //
    vector<int> rdm = random_vector(1707815, 100000000);

    // Execution and time measurement //
    for (int i = 0 ; i < 7 ; i++) {
        auto start = high_resolution_clock::now();
        vector<int> result = bucketSort(rdm);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;
    }
}
    
