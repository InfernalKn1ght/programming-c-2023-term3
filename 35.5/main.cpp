#include <iostream>

int f(int n) {
    return 1 << (n - 1);
}

int main(int argc, char *argv[]) {
    int n = 5;
    std::cout << f(n);

    return EXIT_SUCCESS;
}