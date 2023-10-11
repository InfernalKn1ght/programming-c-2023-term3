#include <ctime>
#include <iostream>

int pair(int a, int b) {
    if (a % 2 != 0 && b % 2 != 0) {
        if (a < b) {
            return 1;
        } else if (a > b) {
            return -1;
        } else {
            return 0;
        }
    } else if (a % 2 == 0 && b % 2 == 0) {
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        } else {
            return 0;
        }
    } else if (a % 2 == 0 && b % 2 != 0) {
        return -1;
    } else {
        return 1;
    }
}

int sortParts(int *arr, int head, int tail, int (*f)(int, int)) {
    int x = arr[head];
    int j = head + 1;
    for (int i = head + 1; i <= tail; ++i) {
        if (f(arr[i], x) == -1) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++j;
        }
    }

    --j;
    int temp = arr[head];
    arr[head] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int *arr, int head, int tail, int (*f)(int, int)) {
    if (head < tail) {
        int x = sortParts(arr, head, tail, f);
        quickSort(arr, head, x - 1, f);
        quickSort(arr, x + 1, tail, f);
    }
}

void function(int *arr, int n, int (*f)(int, int)) {
    quickSort(arr, 0, n - 1, f);
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 15;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    function(arr, n, pair);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    return EXIT_SUCCESS;
}