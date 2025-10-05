#include <stdio.h>
//Autor: Leander Decristoforo

int main(void) {

	// Hier sollen Sie die Fibonacci Folge implementieren
	int fibo[20] = {1, 1};
	for (int i = 2; i < 20; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	// Print fibonacci
	fprintf(stdout, "The first 20 fibonacci numbers are:\n");
	for (int i = 0; i < 20; i++) {
		fprintf(stdout, "%d ", fibo[i]);
	}
	fprintf(stdout, "\n");

	return 0;
}
