#include <ctime>
#include <iostream>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        bool f = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                f = 1;
            }
        }
        if (f == 0) break;
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 20;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    bubbleSort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return EXIT_SUCCESS;
}