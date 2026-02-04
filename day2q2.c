#include <stdio.h>

int main() {
    int arr[100];
    int n, pos, i;

   
    if (scanf("%d", &n) != 1) return 1;

 
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    scanf("%d", &pos);

    
    if (pos < 1 || pos > n) {
        printf("Deletion not possible.\n");
    } else {
  
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

       
        n--;

    
        for (i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}


// Example Input/Output: 5
// Enter number of elements in array: 5
// Enter 5 elements:
// 5
// 10 20 30 40 50
// 2

// Enter the position to delete: 2
// Array after deletion:
// 10 30 40 50  
