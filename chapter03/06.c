#include <stdio.h>

typedef struct complex {
	float real;
	float imaginary;
}c1, c2;

int main() {
	c1 first, c2, second;

	first.real = 1.0;
	second.imaginary = 2.0;

	printf("%f", first.real);
	return 0;
}