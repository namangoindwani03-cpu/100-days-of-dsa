#include <stdio.h>

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int temp;

    while (left < right) {
        // Swap elements using a temporary variable
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers toward each other
        left++;
        right--;
    }
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

// This code reads an array of integers, reverses the array in place, and then prints the reversed array.
// It uses a two-pointer technique to swap elements from the start and end of the array until
// the pointers meet in the middle.

// Example Input/Output:
// Input: 5
// 1 2 3 4 5    
// Output: 5 4 3 2 1        
