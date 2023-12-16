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

int linSearch(int **arr, int n, int m, int x) {
    for (int i = 0; i < n * m; ++i) {
        if (arr[i / m][i % n] == x) {
            return i;
        }
    }
    return -1;
}

int binSearch(int **arr, int start, int end, int x, int n, int m) {
    if (start <= end) {
        int middle = start + (end - start) / 2;
        int i = middle / m;
        int j = middle % n;
        if (x > arr[i][j]) {
            return binSearch(arr, middle + 1, end, x, n, m);
        } else if (x < arr[i][j]) {
            return binSearch(arr, start, middle - 1, x, n, m);
        } else {
            return middle;
        }
    } else {
        return -1;
    }
}

void print_matrix(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 15;
    int m = 15;
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % ((i + 1) * 10 - i * 10 + 1) + i * 10;
        }
    }

    print_matrix(arr, n, m);

    int result = linSearch(arr, n, m, 83);
    if (result != -1) {
        int i = result / m;
        int j = result % n;
        std::cout << "(" << i << "," << j << ")\n";
    } else {
        std::cout << "Not found";
    }

    for (int i = 0; i < n; ++i) {
        quickSort(arr[i], 0, m - 1);
    }

    print_matrix(arr, n, m);

    result = binSearch(arr, 0, n * m - 1, 83, n, m);
    if (result != -1) {
        int i = result / m;
        int j = result % n;
        std::cout << "(" << i << "," << j << ")\n";
    } else {
        std::cout << "Not found";
    }

    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return EXIT_SUCCESS;
}