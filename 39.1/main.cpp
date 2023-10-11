#include <iostream>

int linSearch(int *arr, int len, int n) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == n) return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    
    return EXIT_SUCCESS;
}