#include <stdio.h>

int main() {
    int arr[100]; 
    int n, x, pos, i;

   
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    printf("Enter the position (1 to %d): ", n + 1);
    scanf("%d", &pos);

   
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter a position between 1 and %d\n", n + 1);
    } else {
       
        for (i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

       
        arr[pos - 1] = x;
        n++; 
        
        printf("Array after insertion: \n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}


// Example Input/Output: 5
// Enter number of elements in array: 5
// Enter 5 elements:
// 5
// 1 2 4 5 6
// 3
// 3
// Enter the element to insert: 3
// Enter the position (1 to 6): 3
// Array after insertion:
// 1 2 3 4 5 6

