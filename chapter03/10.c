#define N 10
#include <stdio.h>
#include <stdlib.h>

void delete(int array[], int loc) {
	int item = N;
	int* copy_array = (int*)malloc((item - loc) * sizeof(int)); // 현크기 6

	for (int i = 0; i < item - loc; i++) {//6까지
		copy_array[i] = array[loc  + i];
	}


	for (int i = 0; i < item - loc; i++) {
		array[loc - 1 + i] = copy_array[i];
	}
}

int main() {
	int array[N];
	int loc = 4;

	for (int i = 0; i < N; i++) {
		array[i] = i;
	}

	delete(array, loc);
	
	for (int i = 0; i < N; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}