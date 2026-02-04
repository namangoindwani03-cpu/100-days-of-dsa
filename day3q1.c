#include <stdio.h>

int main() {
    int n, k, i;
    int arr[100];
    int found_index = -1;
    int comparisons = 0;

    
    if (scanf("%d", &n) != 1) return 0;

    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    scanf("%d", &k);

   
    for (i = 0; i < n; i++) {
        comparisons++; 
        if (arr[i] == k) {
            found_index = i;
            break; 
        }
    }

    
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

// Example Input/Output: 5
// Enter number of elements in array: 5
// Enter 5 elements:
// 5
// 10 20 30 40 50
// 30
// Enter the key to search: 30
// Found at index 2
// Comparisons = 3  
