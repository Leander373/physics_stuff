#include <stdio.h>
#include <stdlib.h>

//Autor: Leander Decristoforo

int main(int argc, char *argv[]) {

	short unsigned int dimension = 3;

	if (argc != (2 * dimension + 1)) {
		printf("Geben Sie jeweils %d Einträge der 2 Vektoren als Parameter an, dessen Kreuzprodukt berechnet werden soll! Insgesamt also %d Zahlen ;-)\n", dimension, 2 * dimension);
		return 1;
	}
	else {

		// Hier sollen Sie das Kreuzprodukt implementieren
		// Hier sollen Sie das Skalarprodukt implementieren
		double vector1[3], vector2[3], solution[3];

		// Initialize vectors
		for(int i = 0; i < 3; i++) {
			vector1[i] = atof(argv[i + 1]);
			vector2[i] = atof(argv[i + 4]);
		}

		// Calculate cross product
		solution[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
		solution[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
		solution[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

		// Print vector
		fprintf(stdout, "The cross product of the two vectors is \n");
		for(int i = 0; i < 3; i++) {
			fprintf(stdout, "%f\n", solution[i]);
		}
		return 0;
	}
}
