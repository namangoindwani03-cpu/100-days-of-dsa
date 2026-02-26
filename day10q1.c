#include <stdio.h>
#include <string.h>

int isPalindrome(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char s[1001];
    if (scanf("%1000s", s) == 1) {
        if (isPalindrome(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}