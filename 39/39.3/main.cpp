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

int search(int *arr, int size, int x) {
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

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 100;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
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
              << search(arr, n - 1, 51);

    delete[] arr;

    return EXIT_SUCCESS;
}