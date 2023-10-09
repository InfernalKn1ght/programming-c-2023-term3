#include <ctime>
#include <iostream>

int *merge(int *left, int *right, int left_len, int right_len) {
    int *buf = new int[left_len + right_len];

    int left_counter = 0;
    int right_counter = 0;

    for (int i = 0; i < left_len + right_len; ++i) {
        if (left_counter < left_len && right_counter < right_len) {
            if (left[left_counter] < right[right_counter]) {
                buf[i] = left[left_counter];
                ++left_counter;
            } else {
                buf[i] = right[right_counter];
                ++right_counter;
            }
        } else if (left_counter < left_len) {
            buf[i] = left[left_counter];
            ++left_counter;
        } else {
            buf[i] = right[right_counter];
            ++right_counter;
        }
    }

    delete[] left;
    delete[] right;

    return buf;
}

int *mergeSort(int *arr, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;

        int *left = mergeSort(arr, start, middle);
        int *right = mergeSort(arr, middle + 1, end);

        return merge(left, right, middle - start + 1, end - middle);
    } else {
        int *x = new int;
        *x = arr[start];
        return x;
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 30;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    int *temp = mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << temp[i] << " ";
    }

    delete[] arr;
    delete[] temp;

    return EXIT_SUCCESS;
}