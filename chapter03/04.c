#include <stdio.h>

int main() {
	int two[10] = { 1, 2 , 4, 8, 16, 32, 64, 128, 256, 512 };

	for (int i = 0; i < 10; i++) {
		printf("%d ", two[i]);
	}
	return 0;
}