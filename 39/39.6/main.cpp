#include <ctime>
#include <iostream>

int sortParts(double *arr, int head, int tail) {
    double x = arr[head];
    int j = head + 1;
    for (int i = head + 1; i <= tail; ++i) {
        if (arr[i] < x) {
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++j;
        }
    }

    --j;
    double temp = arr[head];
    arr[head] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(double *arr, int head, int tail) {
    if (head < tail) {
        int x = sortParts(arr, head, tail);
        quickSort(arr, head, x - 1);
        quickSort(arr, x + 1, tail);
    }
}

int binSearch(double *arr, int start, int end, double x, int size) {
    if (start <= end) {
        int middle = start + (end - start) / 2;
        if (x > arr[middle]) {
            return binSearch(arr, middle + 1, end, x, size);
        } else if (x < arr[middle]) {
            return binSearch(arr, start, middle - 1, x, size);
        } else {
            std::cout << x << " = " << arr[middle];
            std::cout << "\n";
            return middle;
        }
    } else {
        if (start == size) {
            --start;
        }
        if (arr[start] > x && start - 1 >= 0) {
            std::cout << arr[start - 1] << " < " << x << " < " << arr[start];
        }
        if (arr[start] > x && start - 1 < 0) {
            std::cout << x << " < " << arr[start];
        }
        if (arr[start] < x && start + 1 < size) {
            std::cout << arr[start] << " < " << x << " < " << arr[start + 1];
        }
        if (arr[start] < x && start + 1 >= size) {
            std::cout << arr[start] << " < " << x;
        }
        return -1;
    }
}

double random(double min, double max) {
    return (double)(rand()) / RAND_MAX * (max - min) + min;
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 100;
    double *arr = new double[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = random(0.0, 22.0);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    binSearch(arr, 0, n - 1, 14.1111, n);

    delete[] arr;

    return EXIT_SUCCESS;
}