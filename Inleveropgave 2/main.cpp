#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<vector<int>> distributionPass(int indx, vector<int> n, vector<vector<int>> arr) {
    /*
    This function applies the distribution pass. It uses a formula that grabs the amount of numbers
    needed from a number based on the index (formula: float number % 10^index / 10). The reason we change it to a 
    float is because when we use 103 for example we get 1.03 which we then turn into an int again so it becomes 1.
    It will then take that 1 digit number and add it to the index vector in arr. (So if the digit is 4 then it will be placed in the 14th (4+10) vector.
    This is because we also work with negative numbers and the first 10 vectors are reserved for those. (-4 + 10 becomes 6 which we can use as index)
    After putting all the number in these "buckets" it then returns the vector arr.
    */
    int exp = pow(10, indx);
    for(float num : n) {   
        int first_num = (int(num) % exp / (exp / 10));
        arr[first_num + 10].push_back(num);
    }
    return arr;
}

vector<int> gatheringPass(vector<vector<int>> arr) {
    /*
    This function applies the gathering pass. It takes all the sorted values that have been placed
    in buckets and and places them back into a vector. After placing all numbers into the vector new_n it then returns it.
    */
    vector<int> new_n = {};
    for (vector<int> v : arr) {
        for (int num : v) {
            new_n.push_back(num);
        }
    }
    return new_n;
}

vector<int> bucketSort(vector<int> n) {
    /*
    This is the main bucketsort function. This is where the arr vector is defined and the longest number
    is determined (so that we know how long a number can really get inside the vector). It then starts the for-loop
    that does the sorting. It then returns the now sorted input vector.
    */
    vector<vector<int>> arr = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    int bigNumLen = to_string(*max_element(n.begin(), n.end())).length();
    
    for (int i = 1; i < bigNumLen+1 ; i++) {
        n = gatheringPass(distributionPass(i, n, arr));
    }
    return n;
}

int main() {
    /*
    The main function. An input vector is defined, then the bucketsort function is started and
    its output is "printed".
    */

    vector<int> ten = {22601, -43812, 17126, 44382, 45296, 60164, 74090, -30154, 16376, 99511};
    vector<int> fifty = {9070, -8348, -6961, -685, -5223, 8303, -4446, 5292, 6408, 5864, -4823, -7576, 1277, 7566, -8181, 4856, 
                        -3056, 6593, 3309, 8205, 9673, -5436, 8112, -8402, 3603, 2934, 191, 2899, 1950, 5645, 3042, 8312, -2259, 
                        -609, 7830, 1340, -2029, 4395, 5323, -5023, -5010, -6839, 7018, -3062, -2379, 5899, -3893, -4504, 5133, 9615};
    vector<int> hundred = {-3153, 409, 8773, 3707, -6161, -2075, 239, 1865, 3347, 1028, 3787, -3348, -7786, -3591, 5967, -7377, 
                           -9513, -3761, 8230, 4207, 6741, 6255, -1566, -1996, -6989, -4564, -8400, 2575, -3858, -4466, 6680, -3590, 
                           -4449, 279, -2284, -1860, -1264, 5355, -4093, 9180, -1112, 940, -4324, -1559, -3400, 718, 2339, 6541, -5033, 
                           1982, -6635, 3924, -2497, -280, -1176, 6118, 652, -810, -1405, -381, -6598, -732, -5134, 7439, -9139, 833, -555, 
                           -5137, -4857, 6128, -5649, -9080, -7001, -6511, -3627, 3368, 7374, -2981, 4665, -5516, -5362, -4468, -6185, -1293, 
                           9888, -6822, -1951, -5118, -6873, 1998, 8953, 513, -6252, -268, -3023, -6689, 3834, -3534, -9189, 9669};

    vector<int> n = {103, -642, 16807, -500292562, 113, -395, -628, 24, -45, 62, 53, 5100, 49, 13, 489, -13, 247, 0, -2521, 4, 41, 19, 2489, 424524, 124524, 404524, -622};
    
    // Execution and time measurement //
    auto start = high_resolution_clock::now();

    vector<int> result = bucketSort(ten);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    // Showing results and duration //
    cout << "\nResult: " << endl;

    for (int i : result) {
        cout << to_string(i) << endl;
    }

    cout << "\nTotal duration: " << duration.count() << " microseconds" << endl;
}
