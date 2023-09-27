#include <iostream>

int f(int n, int k) {
    if (n > k && k > 0)
        return f(n - 1, k) + f(n - 1, k - 1);
    else
        return 1;
}

int main(int argc, char *argv[]) {
    std::cout << f(4,2);

    return EXIT_SUCCESS;
}