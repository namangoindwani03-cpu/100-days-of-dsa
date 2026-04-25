// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

// Structure to store candidate and votes
struct Candidate {
    char name[NAME_LEN];
    int votes;
};

// Function to find index of candidate
int findCandidate(struct Candidate arr[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0)
            return i;
    }
    return -1;
}

// Comparator for sorting
void sortCandidates(struct Candidate arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sort by votes (descending)
            if (arr[i].votes < arr[j].votes ||
               (arr[i].votes == arr[j].votes && strcmp(arr[i].name, arr[j].name) > 0)) {
                
                struct Candidate temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];
    
    // Input votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    struct Candidate candidates[MAX];
    int size = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int idx = findCandidate(candidates, size, votes[i]);

        if (idx == -1) {
            strcpy(candidates[size].name, votes[i]);
            candidates[size].votes = 1;
            size++;
        } else {
            candidates[idx].votes++;
        }
    }

    // Sort candidates
    sortCandidates(candidates, size);

    // Winner
    printf("%s\n", candidates[0].name);

    return 0;
}