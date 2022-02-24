#include <iostream>
#include <vector>

using std::cout, std::endl, std::to_string, std::vector, std::reverse, std::copy;

vector<int> merge_sort(vector<int> xs) {
    int unit = 1;
    while (unit <= xs.size()) {
        int h = 0;
        for (int h = 0; h < xs.size(); h += (unit*2)) {
            int l = h;
            vector<int> v = {int(xs.size()), h + 2 * unit};
            int r = *min_element(v.begin(), v.end());
            int mid = h + unit;
            int p = l;
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

    vector<int> input = {123, 53, 2, 6, 75, 35, 78, 29, 10, 90};
    vector<int> result = merge_sort(input);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}
