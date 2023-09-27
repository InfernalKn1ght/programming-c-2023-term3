#include <iostream>

int f(int n, int k) {
    if (n == 1 || k == 1) {
        return 1;
    } else if (n < k) {
        return f(n, n);
    } else if (n == k) {
        return f(n, k - 1) + 1;
    } else {
        return f(n - k, k) + f(n, k - 1);
    }
}

int main(int argc, char *argv[]) {
    int n = 4;
    std::cout << f(n, n);

    return EXIT_SUCCESS;
}