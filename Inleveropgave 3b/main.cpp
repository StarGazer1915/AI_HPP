#include <iostream>
#include <vector>
#include <thread>
#include <future>

using std::cout, std::endl, std::to_string, std::vector, std::thread;

vector<int> merge_sort_iterative(vector<int> xs, int num_of_threads) {
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

vector<int> sort_and_merge(vector<int> array1, vector<int> array2) {
    return vector<int>{};
}

vector<int> multi_thread_merge_sort(vector<int> xs, int num_of_threads) {
    int part = xs.size() / num_of_threads;
    thread thr[num_of_threads];
    vector<vector<int>> sliced_vector;

    for (int slice = 0 ; slice < num_of_threads ; slice += part) {
        vector<int> v_part(xs.begin() + slice, xs.begin() + slice + part - 1);
        sliced_vector.push_back(v_part);
    }

    int t = 0;
    while (sliced_vector.size() != 1) {
        for (int i = 0 ; i < sliced_vector.size() ; i += 2) {
            thr[t] = thread(sort_and_merge, sliced_vector[i], sliced_vector[i+1]);
        }
        for (int t = 0; t < num_of_threads; t++) {
            thr[t].join();
        }      
    }
    return sliced_vector[0];    
}


int main() {

    vector<int> input = {12, 902, -3, 85, 93, -24, 7, 432};
    vector<int> result = multi_thread_merge_sort(input, 4);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}
