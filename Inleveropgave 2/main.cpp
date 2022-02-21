#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getFirstDigit(int n) {
    /*
    This function removes the last digit of a number until the leftmost digit remains.
    So if we take the number 103 it removes 3, then 0 and then returns 1.
    */
    while (n >= 10)
        n /= 10;
    return n;
}

vector<vector<int>> distributionPass(int indx, vector<int> n, vector<vector<int>> arr) {
    /*
    This function applies the distribution pass. It uses a formula that grabs the amount of numbers
    needed from a number based on the index (formula: number % 10^index). So it will start with one number,
    then two, three, etc. It works from right to left so it will start with 000(0) then 00(00) then 0(000), etc.
    It will then take the number and if it's a 1 digit number it will add it to the index 0 vector in arr. If not
    then it will place it on the index vector that corresponds with the actual number. (So if the digit is 4 then-
    vector that the entire number will be put in will be index vector 4 from vector arr.) After putting all the
    number in these "buckets" it then returns the vector arr.
    */
    int exp = pow(10, indx);
    for (int num : n) {
        if (to_string(num).length() >= indx) {
            arr[getFirstDigit(num % exp)].push_back(num);
        } else {
            arr[0].push_back(num);
        }
    }
    return arr;
}

vector<int> gatheringPass(vector<vector<int>> arr) {
    /*
    This function applies the gathering pass. It takes all the sorted values that have been placed
    in buckets and and places them back into a vector. (from vector 0 to vector 9)
    After placing all those numbers into the vector new_n it then returns it.
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
    This is the main bucketsort function. This is where the arr vector is defined and the largest number
    is determined (so that we know how long a number can really get inside the vector). It then starts the for-loop
    that does the sorting. It then returns the now sorted input vector.
    */
    vector<vector<int>> arr = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
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
    vector<int> n = {103, 24, 62, 51, 49, 13, 489, 247, 0, 4};
    
    for (int i : bucketSort(n)) {
        cout << to_string(i) << endl;
    }

}
