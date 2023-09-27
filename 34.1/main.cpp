#include <iostream>

int **create(int n) {
    int **matrix = new int *[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

int *access(int **matrix, int i, int j) {
    static int a = 0;
    a = 0;

    if (i / 10 == j / 10) {
        return &matrix[i % 10][j];
    } else {
        return &a;
    }
}

void destroy(int** matrix) {
    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char *argv[]) {
    int** matrix = create(100);
    int i = 18;
    int j = 11;

    matrix[i % 10][j] = 99;

    std::cout << *access(matrix, i, j);

    destroy(matrix);

    return EXIT_SUCCESS;
}