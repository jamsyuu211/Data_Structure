#define _CRT_SECURE_N0_WARNINGS
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

typedef struct {
	int n;
	char text[20];
}Num;

int main() {
	Num *num = (Num*)malloc(sizeof(Num));

	num->n = 100;
	strcpy(num->text, "just testing");

	free(num);
	return 0;	
}