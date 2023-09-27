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

    int *arrBuf = new int[n];
    for (int i = 0; i < n; ++i) {
        arrBuf[i] = arr[i];
    }
    int counter = 0;

    while (counter != n) {
        counter = 0;
        for (int i = 0; i < n; ++i) {
            if (arrBuf[i] == 0) ++counter;
            matrix[arrBuf[i] % 10][i] = arr[i];
            arrBuf[i] /= 10;
        }

        if (counter == n) break;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';

        int k = 0;
        for (int i = 0; i < 10; ++i) {
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
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 10;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    sort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return EXIT_SUCCESS;
}