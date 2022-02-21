#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// using std::vector, std::string, std::cout, std::endl;

int getFirstDigit(int n) {
    while (n >= 10)
        n /= 10;

    return n;
}

vector<vector<int>> distributionPass(int indx, vector<int> n, vector<vector<int>> arr) {
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
    vector<int> new_n = {};
    for (vector<int> v : arr) {
        for (int num : v) {
            new_n.push_back(num);
        }
    }
    return new_n;
}

vector<int> bucketSort(vector<int> n) {
    vector<vector<int>> arr = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    int bigNumLen = to_string(*max_element(n.begin(), n.end())).length();
    
    for (int i = 1; i < bigNumLen+1 ; i++) {
        n = gatheringPass(distributionPass(i, n, arr));
    }
    return n;
}

int main()
{
    vector<int> n = {103, 24, 62, 51, 49, 13, 489, 247, 0, 4};
    
    for (int i : bucketSort(n)) {
        cout << to_string(i) << endl;
    }

}
