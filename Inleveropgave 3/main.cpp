#include <iostream>
#include <vector>

using std::cout, std::endl, std::to_string, std::vector, std::reverse, std::copy;

vector<int> merge_sort(vector<int> xs) {
    int unit = 1;
    while (unit <= xs.size()) {
        for (int h = 0; h < xs.size(); h += (unit*2)) {
            vector<int> v = {int(xs.size()), (h + (2 * unit))};
            int r = *min_element(v.begin(), v.end());
            int mid = h + unit;
            int p = h;
            int q = mid;
            // cout << "pppp " << to_string(h) << endl;
            while (p < mid && q < r) {
                if (xs[p] <= xs[q]) {
                    p += 1;
                } else {
                    int tmp = xs[q];
                    for (int i = p; i < q; i++) {
                        xs[i+1] = xs[i];
                    }
                    xs[p] = tmp;
                    p += 1;
                    mid += 1;
                    q += 1;
                }
            }
        }
        unit *= 2;
    }
    return xs;
}


int main() {

    vector<int> input = {123, 53, 2, 6, 75, 35, 78, 29, 10};
    vector<int> result = merge_sort(input);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}