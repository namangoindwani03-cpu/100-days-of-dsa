// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // Hash map using array (for simplicity)
    // Use large size and initialize with -1
    int hash[100000] = {0};

    for (int i = 0; i < 100000; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is 0
        if (sum == 0) {
            max_length = i + 1;
        }

        // Convert negative index handling
        int index = sum + 50000;

        // Case 2: sum seen before
        if (hash[index] != -1) {
            int length = i - hash[index];
            if (length > max_length)
                max_length = length;
        } else {
            hash[index] = i;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest zero sum subarray: %d\n", maxLen(arr, n));

    return 0;
}