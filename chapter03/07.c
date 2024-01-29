#include <stdio.h>

typedef struct complex {
	float real;
	float imag;
}Complex;

Complex complex_add(Complex a, Complex b) {
	Complex add;
	add.real = a.real + b.real;
	add.imag = a.imag + b.imag;
	return add;
}

int main() {
	Complex a = { 1, 1 };
	Complex b = { 2, 2 };
	Complex c = complex_add(a, b);
	printf("%f %f", c.real, c.imag);
	return 0;
}