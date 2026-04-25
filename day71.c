// Implement a hash table using quadratic probing with formula:
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Inserted %d at index %d\n", key, index);
    } else {
        printf("Collision at index %d for key %d\n", index, key);

        int i = 1;
        int newIndex;

        while (i < SIZE) {
            newIndex = (index + i * i) % SIZE;

            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                printf("Inserted %d at index %d\n", key, newIndex);
                return;
            }
            i++;
        }

        printf("Hash table is full, cannot insert %d\n", key);
    }
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

// Main function
int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(33);

    display();

    return 0;
}