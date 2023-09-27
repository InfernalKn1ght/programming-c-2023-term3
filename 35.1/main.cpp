#include <iostream>

void f1(int n) {
    if (n / 10 > 0) f1(n / 10);
    std::cout << n % 10 << ' ';
}

void f2(int n) {
    std::cout << n % 10 << ' ';
    if (n / 10 > 0) f2(n / 10);
}

int main(int argc, char *argv[]) {
    f1(0);
    std::cout << '\n';
    f2(12345670);

    return EXIT_SUCCESS;
}