#include <iostream>
#include <vector>
#include <thread>
#include <future>

using std::cout, std::endl, std::to_string, std::vector, std::thread, std::future, std::launch;

vector<int> merge_sort_iterative(vector<int> xs) {
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

vector<int> merge_sorted_arrays(vector<int> array1, vector<int> array2) {
    if (array1.size() == 0 && array2.size() == 0) {
        return vector<int> {};
    } else { 
        if (array1.size() == 0) {
            vector<int> header2 = {array2[0]};
            vector<int> tail2(array2.begin() + 1, array2.end());
            
            vector<int> new_arr = merge_sorted_arrays(array1, tail2);
            header2.insert(header2.end(), new_arr.begin(), new_arr.end());

            return header2;
        } else if (array2.size() == 0) {
            vector<int> header1 = {array1[0]};
            vector<int> tail1(array1.begin()+1, array1.end());
            vector<int> new_arr = merge_sorted_arrays(tail1, array2);

            header1.insert(header1.end(), new_arr.begin(), new_arr.end());
            return header1;
            
        } else {
            vector<int> header1 = {array1[0]};
            vector<int> header2 = {array2[0]};
            vector<int> tail1(array1.begin() + 1, array1.end());
            vector<int> tail2(array2.begin() + 1, array2.end());

            if (header1[0] < header2[0]) {   
                vector<int> new_arr = merge_sorted_arrays(tail1, array2);
                header1.insert(header1.end(), new_arr.begin(), new_arr.end());
                return header1;
            } else {
                vector<int> new_arr = merge_sorted_arrays(array1, tail2);
                header2.insert(header2.end(), new_arr.begin(), new_arr.end());
                return header2;
            }
        }
    }
}

vector<vector<int>> slice_vector(vector<int> xs, int num_of_threads) {
    int part = xs.size() / num_of_threads / 2;
    vector<vector<int>> sliced_vector;

    for (int slice = 0 ; slice < xs.size() ; slice += part) {
        vector<int> v_part(xs.begin() + slice, xs.begin() + slice + part);
        sliced_vector.push_back(v_part);
    }
    return sliced_vector;
}

vector<int> sort_and_merge(vector<int> array1, vector<int> array2) {
    vector<int> sorted_ar1 = merge_sort_iterative(array1);
    vector<int> sorted_ar2 = merge_sort_iterative(array2);
    return merge_sorted_arrays(array1, array2);
}

vector<int> multi_thread_merge_sort(vector<int> xs, int num_of_threads) {
    vector<vector<int>> sliced_vector = slice_vector(xs, num_of_threads);

    future<vector<int>> thr_0 = async(launch::async, &sort_and_merge, sliced_vector[0], sliced_vector[1]);
    future<vector<int>> thr_1 = async(launch::async, &sort_and_merge, sliced_vector[2], sliced_vector[3]);
    future<vector<int>> thr_2 = async(launch::async, &sort_and_merge, sliced_vector[4], sliced_vector[5]);
    future<vector<int>> thr_3 = async(launch::async, &sort_and_merge, sliced_vector[6], sliced_vector[7]);

    future<vector<int>> thr_4 = async(launch::async, &sort_and_merge, thr_0.get(), thr_1.get());
    future<vector<int>> thr_5 = async(launch::async, &sort_and_merge, thr_2.get(), thr_3.get());

    future<vector<int>> thr_6 = async(launch::async, &sort_and_merge, thr_4.get(), thr_5.get());
    
    return thr_6.get();
}

int main() {

    vector<int> input = {12, 902, 3, 85, 93, 250, 7, 432, 18, 42, 31, 443, 84, 101, 24, 95};
    vector<int> result = multi_thread_merge_sort(input, 4);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}
