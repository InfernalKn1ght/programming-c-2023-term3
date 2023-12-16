#include <iostream>

int f(int n) {
    if (n == 1)
        return 3;
    else if (n == 2)
        return 2;
    else {
        return (f(n - 1) + 1) * f(n - 1) - 1;
    }
}

int main(int argc, char *argv[]) {
    std::cout << f(4);
    return EXIT_SUCCESS;
}