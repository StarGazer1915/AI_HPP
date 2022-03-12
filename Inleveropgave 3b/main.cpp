#include <iostream>
#include <vector>
#include <future>

using std::cout, std::endl, std::to_string, std::vector, std::future, std::launch;

vector<int> merge_arrays(vector<int> array1, vector<int> array2) {
    if (array1.size() == 0 && array2.size() == 0) {
        return vector<int> {};
    } else {
        if (array1.size() == 0) {
            vector<int> header2 = {array2[0]};
            vector<int> tail2(array2.begin() + 1, array2.end());
            
            vector<int> new_arr = merge_arrays(array1, tail2);
            header2.insert(header2.end(), new_arr.begin(), new_arr.end());

            return header2;
        } else if (array2.size() == 0) {
            vector<int> header1 = {array1[0]};
            vector<int> tail1(array1.begin()+1, array1.end());
            vector<int> new_arr = merge_arrays(tail1, array2);

            header1.insert(header1.end(), new_arr.begin(), new_arr.end());
            return header1;
            
        } else {
            vector<int> header1 = {array1[0]};
            vector<int> header2 = {array2[0]};
            vector<int> tail1(array1.begin() + 1, array1.end());
            vector<int> tail2(array2.begin() + 1, array2.end());

            if (header1[0] < header2[0]) {   
                vector<int> new_arr = merge_arrays(tail1, array2);
                header1.insert(header1.end(), new_arr.begin(), new_arr.end());
                return header1;
            } else {
                vector<int> new_arr = merge_arrays(array1, tail2);
                header2.insert(header2.end(), new_arr.begin(), new_arr.end());
                return header2;
            }
        }
    }
}

vector<int> recursive_merge_sort(vector<int> xs) {
    if (xs.size() == 1) {
        return xs;
    } else {
        int middle = xs.size()/2;
        vector<int> first(xs.begin(), xs.begin() + middle);
        vector<int> second(xs.begin() + middle, xs.end());
        return merge_arrays(recursive_merge_sort(first), recursive_merge_sort(second));
    }
}

vector<vector<int>> slice_vector(vector<int> xs, int num_of_threads) {
    int part = xs.size() / num_of_threads;
    vector<vector<int>> sliced_vector;

    for (int slice = 0 ; slice < xs.size() ; slice += part) {
        vector<int> v_part(xs.begin() + slice, xs.begin() + slice + part);
        sliced_vector.push_back(v_part);
    }
    return sliced_vector;
}

vector<int> multi_thread_merge_sort(vector<int> xs, int num_of_threads) {
    vector<vector<int>> sliced_vector = slice_vector(xs, num_of_threads);

    future<vector<int>> thr_0 = async(launch::async, &recursive_merge_sort, sliced_vector[0]);
    future<vector<int>> thr_1 = async(launch::async, &recursive_merge_sort, sliced_vector[1]);
    future<vector<int>> thr_2 = async(launch::async, &recursive_merge_sort, sliced_vector[2]);
    future<vector<int>> thr_3 = async(launch::async, &recursive_merge_sort, sliced_vector[3]);

    vector<int> arr_1 = merge_arrays(thr_0.get(), thr_1.get());
    vector<int> arr_2 = merge_arrays(thr_2.get(), thr_3.get());
    
    return merge_arrays(arr_1, arr_2);
}

vector<int> random_vector(int seed, int num_of_rands) {
    /*
    This function returns a vector filled with random numbers based on the given seed and
    amount of numbers requested.
    */
    srand(seed);
    vector<int> rV(num_of_rands, 0);
    generate(rV.begin(), rV.end(), rand);
    return rV;
}

int main() {

    vector<int> input = {12, 902, 3, 85, 93, -250, 7, -432, 18, 42, 31, 443, 84, 101, 24, 95};
    vector<int> ran_input = random_vector(1707815, 2000);
    vector<int> result = multi_thread_merge_sort(ran_input, 4);

    for (int i : result) {
        cout << to_string(i) << endl;
    }
}
