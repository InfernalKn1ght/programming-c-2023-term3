#include <ctime>
#include <iostream>

int find_row(int **arr, int *row, int left, int right, int m) {
    int answer = 0;

    for (int j = 0; j < m; ++j) {
        int new_left = -1;
        int new_right = -1;

        for (int i = left; i <= right; ++i) {
            if (row[j] == arr[i][j] && new_left == -1) {
                new_left = i;
            }
            if (row[j] == arr[i][j]) {
                new_right = i;
            }
        }

        if (new_left == -1 || new_right == -1) {
            return -1;
        }

        right = new_right;
        left = new_left;
        answer = new_left;
    }

    return answer;
}

void print_matrix(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    srand(time(0));

    int n = 8;
    int m = 5;

    int matrix[8][5] = {{0, 0, 0, 1, 2},
                        {0, 0, 0, 2, 2},
                        {0, 0, 1, 1, 2},
                        {0, 0, 1, 1, 2},
                        {0, 0, 2, 0, 2},
                        {0, 3, 0, 1, 2},
                        {4, 0, 1, 1, 2},
                        {5, 0, 0, 1, 2}
                       };


    int** arr = new int*[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = &matrix[i][0];
    }
    print_matrix(arr, n, m);

    int buf[5] = {0, 0, 0, 2, 3};
    int *row = &buf[0];

    for (int i = 0; i < m; ++i) {
        std::cout << row[i] << " ";
    }
    std::cout << "\n";
    std::cout << find_row(arr, row, 0, n -1, m);

    return EXIT_SUCCESS;
}