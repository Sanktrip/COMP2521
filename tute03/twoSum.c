#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Pseudocode
/*
List A

int x
sum += element1
for element in A 
    sum += x * element
    x = x * x







*/

bool twoSum(int *nums, int target, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                return true;
            }
        }
    }
    return false;
}






int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Arguments are invalid");
        return 1;
    }
    int nums[argc - 1];
    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);

    }
    int target;
    printf("Enter target: ");
    scanf("%d", &target);
    bool sum = twoSum(nums, target, 5);
    printf("%d\n", sum);
    return 0;
}