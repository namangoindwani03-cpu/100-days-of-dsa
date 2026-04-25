// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <stdbool.h>

char repeatedCharacter(char* s) {
    bool seen[26] = {false};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index]) {
            return s[i];  // first repeated character
        }

        seen[index] = true;
    }

    return '\0'; // if no repetition (edge case)
}

// Example usage
int main() {
    char s[] = "abccbaacz";
    char result = repeatedCharacter(s);

    if (result != '\0')
        printf("First repeated character: %c\n", result);
    else
        printf("No repeated character found\n");

    return 0;
}