#include <stdio.h>
#include <string.h>

void mirror(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[1001];
    if (scanf("%1000s", str) == 1) {
        mirror(str);
        printf("%s\n", str);
    }
    return 0;
}
