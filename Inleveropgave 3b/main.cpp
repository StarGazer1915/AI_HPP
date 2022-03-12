#include <iostream>
#include <vector>
#include <thread>

using std::cout, std::endl, std::to_string, std::vector;

vector<int> merge_sort(vector<int> xs, int num_of_threads) {
    /*
    In-place merge sort of vector without recursion. The basic idea
    is to avoid the recursive call while using an iterative solution.
    The algorithm first merges a chunk of a length of 2, then it merges 
    chunks the length of 4, then 8, 16, .... , until 2^k where 2^k is larger
    than the length of the array. It then returns the now sorted list.
    */
    int unit = 1;
    while (unit <= xs.size()) {
        for (int h = 0; h < xs.size(); h += (unit*2)) {
            vector<int> v = {int(xs.size()), h + 2 * unit};
            int r = *min_element(v.begin(), v.end());
            int mid = h + unit;
            int p = h;
            int q = mid;

            while (p < mid && q < r) {
                if (xs[p] <= xs[q]) {
                    p += 1;
                } else {
                    xs.insert(xs.begin()+p, xs[q]);
                    xs.erase(xs.begin()+q+1);
                    p++;
                    mid++;
                    q++;
                }
            }
        }
        unit *= 2;
    }
    for (int i : xs) {
        cout << to_string(i) << endl;
    }
    return xs;
}

vector<int> merge_arrays(vector<int> start, vector<int> array1, vector<int> array2) {
    // when both still have elements
    int head1 = array1[0];
    int head2 = array2[0];
    vector<int> tail1 = vector<int>(array1.begin() + 1, array1.end());
    vector<int> tail2 = vector<int>(array2.begin() + 1, array2.end());
    if (head1 < head2) {
        return vector<int>{head1} + merge_arrays(start, tail1, array2); // and merge with the remainder
    } else {
        return vector<int>{head2} + merge_arrays(start, array1, tail2); // idem for when array 2 had the smaller element
    }   
}


int main() {

    vector<int> input = {12, 902, -3, 85, 93, -24, 7, 432};

    vector<int> start = {};
    vector<int> input1 = {-3, 12, 85, 902};
    vector<int> input2 = {-24, 7, 93, 432};
    
    std::thread worker(merge_arrays, start, input1, input2);
    
    worker.join();
}
