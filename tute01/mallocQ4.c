#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *a[0] = malloc(sizeof(int)*5);
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}

}
