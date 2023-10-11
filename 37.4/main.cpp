#include <ctime>
#include <iostream>

void sort(int *arr, int n) {
    int **matrix = new int *[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = -1;
        }
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
        max = std::max(max, arr[i]);
    }

    int l = 0;
    while (max != 0) {
        for (int i = 0; i < n; ++i) {
            int temp = arr[i];
            for (int j = 0; j < l; ++j) {
                temp /=10;
            }
            matrix[temp % 10][i] = arr[i];
        }
        for (int i = 0, k = 0; i < 10; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != -1) {
                    arr[k] = matrix[i][j];
                    ++k;
                }
            }
        }

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = -1;
            }
        }
        max /= 10;
        ++l;
    }

    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 1000;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    sort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return EXIT_SUCCESS;
}