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

int binSearch(int *arr, int start, int end, int x) {
    if (start <= end) {
        int middle = start + (end - start) / 2;
        if (x > arr[middle]) {
            return binSearch(arr, middle + 1, end, x);
        } else if (x < arr[middle]) {
            return binSearch(arr, start, middle - 1, x);
        } else {
            if (middle > 0 && arr[middle - 1] == x) {
                return binSearch(arr, start, middle - 1, x);
            } else {
                return middle;
            }
        }
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 20;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n"
              << binSearch(arr, 0, n - 1, 5);

    delete[] arr;

    return EXIT_SUCCESS;
}