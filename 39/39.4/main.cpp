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

int interpolationSearch(int *arr, int size, int x) {
    int low = 0;
    int high = size - 1;

    while (arr[low] < x && arr[high] > x) {
        if (arr[low] == arr[high]) {
            break;
        }
        int est_middle = low + (high - low) * (x - arr[low]) / (arr[high] - arr[low]);

        if (x < arr[est_middle]) {
            high = est_middle - 1;
        } else if (x > arr[est_middle]) {
            low = est_middle + 1;
        } else {
            return est_middle;
        }
    }

    if (arr[low] == x) {
        return low;
    }
    if (arr[high] == x) {
        return high;
    }
    return -1;
}

int binSearch(int *arr, int start, int end, int x) {
    if (start <= end) {
        int middle = start + (end - start) / 2;
        if (x > arr[middle]) {
            return binSearch(arr, middle + 1, end, x);
        } else if (x < arr[middle]) {
            return binSearch(arr, start, middle - 1, x);
        } else {
            return middle;
        }
    } else {
        return -1;
    }
}

int linSearch(int *arr, int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 10000;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 30000;
    }

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        int index = rand() % n;
        linSearch(arr, n, arr[index]);
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "linear seacrh, array is not sorted | time: " << seconds << "\n";

    quickSort(arr, 0, n - 1);

    start = clock();
    for (int i = 0; i < 10000; ++i) {
        int index = rand() % n;
        binSearch(arr, 0, n - 1, arr[index]);
    }
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "binary seacrh, array is sorted | time: " << seconds << "\n";

    start = clock();
    for (int i = 0; i < 10000; ++i) {
        int index = rand() % n;
        interpolationSearch(arr, n, arr[index]);
    }
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "interpolation seacrh, array is sorted | time: " << seconds << "\n";

    delete[] arr;

    return EXIT_SUCCESS;
}