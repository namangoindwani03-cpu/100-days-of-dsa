#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int current, previous;
    
   
    scanf("%d", &previous);
    printf("%d", previous);

    for (int i = 1; i < n; i++) {
        scanf("%d", &current);
      
        if (current != previous) {
            printf(" %d", current);
            previous = current;
        }
    }
    printf("\n");

    return 0;
}