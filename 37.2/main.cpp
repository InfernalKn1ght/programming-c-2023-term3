#include <ctime>
#include <iostream>

void sort(int *arr, int n) {
    int *min = new int;
    *min = 1000000;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n; ++j) {
            if (*min > arr[j]) min = &arr[j];
        }
        int temp = *min;
        *min = arr[i];
        arr[i] = temp;
    }
}

void sort2(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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

    sort2(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return EXIT_SUCCESS;
}