#include <iostream>
#include <vector>

using std::cout, std::endl, std::to_string, std::vector, std::reverse, std::copy;

vector<int> merge_sort(vector<int> xs) {
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
    return xs;
}


int main() {

    vector<int> input = {123, -53, 2, 6, 75, 35, 7800, -29, 10, 90};
    vector<int> result = merge_sort(input);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}
