#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Palindrome PseudoCode 
/*



*/

bool isPalindrome(char *s) {
    int start = 0;
    int end = strlen(s) - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }


    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Arguments are invalid");
        return 1;
    }
    bool palin = isPalindrome(argv[1]);
    printf("%d\n", palin);
    return 0;
}