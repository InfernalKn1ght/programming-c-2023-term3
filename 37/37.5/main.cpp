#include <ctime>
#include <iostream>

int sortParts(int *arr, int head, int tail) {
    int x = arr[head];
    int j = head + 1;
    for (int i = head + 1; i <= tail; ++i) {
        if (arr[i] < x) {
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

void quickSort(int *arr, int head, int tail) {
    if (head < tail) {
        int x = sortParts(arr, head, tail);
        quickSort(arr, head, x - 1);
        quickSort(arr, x + 1, tail);
    }
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

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return EXIT_SUCCESS;
}