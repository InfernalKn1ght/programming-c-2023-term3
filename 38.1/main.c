#include <stdio.h>
#include <stdlib.h>

char function(char (*f)(char, char), char (*g)(char, char), char *M) {
    char temp = f(g(f(M[0], M[1]), M[2]), M[3]);
    for (int i = 4; i < 80; i+=4) {
        char temp1 = f(g(f(M[i], M[i + 1]), M[i + 2]), M[i + 3]);
        temp = f(temp, temp1);
    }
    return temp;
}

int main(int argc, char *argv[]) {
    printf("%c", ' ');
    return EXIT_SUCCESS;
}