#include <ctime>
#include <iostream>

void heapSort(int *arr, int start, int end) {
    
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

    heapSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    
    return EXIT_SUCCESS;
}