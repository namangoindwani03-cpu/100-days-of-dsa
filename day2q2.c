#include <stdio.h>

int main() {
    int arr[100];
    int n, pos, i;

    // Input the size of the array
    if (scanf("%d", &n) != 1) return 1;

    // Input the array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the position to delete
    scanf("%d", &pos);

    // Validation: Ensure position is within bounds
    if (pos < 1 || pos > n) {
        printf("Deletion not possible.\n");
    } else {
        // Shift elements to the left
        // Start from the target index and overwrite with the next element
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Decrease the size of the array
        n--;

        // Print the updated array
        for (i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}

// This code allows the user to delete an element at a specified position in an array.
// It first validates the position and then shifts the elements to fill the gap left by the deleted element.
// Finally, it prints the updated array.    

// Example Input/Output: 5
// Enter number of elements in array: 5
// Enter 5 elements:
// 5
// 10 20 30 40 50
// 2

// Enter the position to delete: 2
// Array after deletion:
// 10 30 40 50  