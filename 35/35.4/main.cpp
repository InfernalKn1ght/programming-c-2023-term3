#include <iostream>

int f(int n, int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) {
        int a = f(n, k >> 1);
        std::cout << "+1\n";
        return a * a;
    } else {
        std::cout << "+1\n";
        return f(n, k - 1) * n;
    }
   
}

int main(int argc, char *argv[]) {
    std::cout << f(3, 9);

    return EXIT_SUCCESS;
}