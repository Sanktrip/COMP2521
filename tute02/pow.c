#include <stdio.h>
#include <stdlib.h>

int pow(int x, unsigned int n) {
    if (n == 1) return x;
    if (n == 0) return 1;

    if (n % 2 == 1) {
        return x * pow(x * x , n/2);
    } else {
        return pow(x * x, n/2);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Provide inpit!");
        exit(1);
    }
    printf("%d : %d\n", atoi(argv[1]), pow(atoi(argv[1]), atoi(argv[2])));
}