#include <iostream>

void f(int n, int a, int b, int mid) {
    if (n > 0) {
        f(n-1, a, mid, b);
        std::cout << a << "->" << b << '\n';
        f(n-1, mid, b, a);
    }
}

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;

    f(n, 1, 3, 2);

    return EXIT_SUCCESS;
}