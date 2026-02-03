#include <stdio.h>

int main() {
    int n, k, i;
    int arr[100];
    int found_index = -1;
    int comparisons = 0;

    // Input size
    if (scanf("%d", &n) != 1) return 0;

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search Logic
    for (i = 0; i < n; i++) {
        comparisons++; // Increment comparison count for every check
        if (arr[i] == k) {
            found_index = i;
            break; // Stop searching once found
        }
    }

    // Output results
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

// This code performs a linear search on an array to find a specified key.
// It counts the number of comparisons made during the search and outputs the index of the found element
// or indicates if the element was not found, along with the total comparisons made.            

// Example Input/Output: 5
// Enter number of elements in array: 5
// Enter 5 elements:
// 5
// 10 20 30 40 50
// 30
// Enter the key to search: 30
// Found at index 2
// Comparisons = 3  