#include <stdio.h>
#include <stdlib.h>

//Autor: Leander Decristoforo

int main(int argc, char *argv[]) {

	short unsigned int dimension = 3;

	if (argc != (2 * dimension + 1)) {
		printf("Geben Sie jeweils %d Einträge der 2 Vektoren als Parameter an, deren Skalarprodukt berechnet werden soll! Insgesamt also %d Zahlen ;-)\n", dimension, 2 * dimension);
		return 1;
	}
	else {

		// Hier sollen Sie das Skalarprodukt implementieren
		double vector1[3], vector2[3];
		double solution = 0;

		// Initialize vectors
		for (int i = 0; i < 3; i++) {
			vector1[i] = atof(argv[i + 1]);
			vector2[i] = atof(argv[i + 4]);
		}

		for (int i = 0; i < 3; i++) {
			solution += vector1[i] * vector2[i];
		}

		fprintf(stdout, "The scalarproduct of the two vectors %f\n", solution);
		return 0;
	}
}
