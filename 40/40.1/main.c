#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_name(char s[]) { // а)
    char *start = strrchr(s, '\\');
    if (start) {
        int index = start - &s[0] + 1;
        char dest[1024];
        strncpy(dest, s, index);
        printf("%s\n", dest);
    } else {
        printf("%s", "");
    }
}

void print_file_name(char s[]) { // б)
    char *start = strrchr(s, '\\');
    if (start) {
        int index = start - &s[0] + 1;
        int len = &s[strlen(s)] - start;
        char dest[1024];
        strncpy(dest, s + index, len);
        printf("%s\n", dest);
    } else {
        printf("%s\n", s);
    }
}

void print_ext(char s[]) { // в)
    char *start = strrchr(s, '.');
    if (start) {
        int index = start - &s[0] + 1;
        int len = &s[strlen(s)] - start;
        char dest[1024];
        strncpy(dest, s + index, len);
        printf("%s\n", dest);
    } else {
        printf("%s", "");
    }
}

void print_file_name_without_ext(char s[]) { // г)
    char dest[1024];
    char *start1 = strrchr(s, '\\');
    char *start2 = strrchr(s, '.');
    int index1 = 0;
    int index2 = 0;
    if (start1) {
        index1 = start1 - &s[0] + 1;
    }
    if (start2) {
        index2 = start2 - &s[0] - 1;
    }
    int len = index2 > index1 ? index2 - index1 + 1 : strlen(s) - index1;
    strncpy(dest, s + index1, len);
    dest[len] = '\0';
    printf("%s\n", dest);
}


int main(int argc, char **argv) {
    char s[1024];
    scanf("%s", s);
    print_path_name(s);
    print_file_name(s);
    print_ext(s);
    print_file_name_without_ext(s);

    return EXIT_SUCCESS;
}