#define n 10
#include <stdio.h>
#include <stdlib.h>

void insert(int array[], int loc, int value) {
	int item = n;
	int copy_array[5] = { 0, };

	for (int i = 0; i < item - loc; i++) {
		copy_array[i] = array[loc - 1 + i];
	}
	
	array[loc - 1] = value;

	for (int i = 0; i < 5; i++) {
		array[loc + i] = copy_array[i];
	}
}

int main() {
	int array[n];
	int loc = 5;
	int value = 999;

	for (int i = 0; i < 10; i++) {
		array[i] = i;
	}

	insert(array, loc, value);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}