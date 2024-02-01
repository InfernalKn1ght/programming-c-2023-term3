#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int entry_number(char s1[], char s2[]) {
    int counter = 0;
    char* buf = strstr(s1, s2);
    while (buf) {
        int index = buf - &s1[0] + 1;
        buf = strstr(s1 + index, s2);
        ++counter;
    }
    return counter;
}

int main(int argc, char **argv) {
    char s1[1024];
    char s2[1024];
    scanf("%s%s", s1, s2);
    printf("%i", entry_number(s1, s2));
    
    return EXIT_SUCCESS;
}