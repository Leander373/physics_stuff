#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Definition des bool'schen Variablentyps

#define DIM 3 // Der Compiler ersetzt von nun an DIM durch 3
// Autor: Leander Decristoforo

void matrixVektorMultiplikation(double matrix[DIM][DIM], double vektor[DIM], double ergebnis[DIM]) {
	/* Implementieren Sie hier die Matrix-Vektor Multiplikation */
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			ergebnis[i] += matrix[i][j] * vektor[j];
		}
	}
}

void pruefeEigenvektor(double vektorVorher[DIM], double vektorNachher[DIM]) {
	bool istEigenvektor = true;
	double lambda, precision = 0.00000001, current = 0;

	/* Überprüfen Sie hier ob es sich um einen Eigenvektor handelt
	   und setzen sie die Variablen istEigenvektor und lambda entsprechend */
	if (vektorVorher[0] != 0) {
		lambda = vektorNachher[0] / vektorVorher[0];
	}
	else if (vektorVorher[1] != 0) {
		lambda = vektorNachher[1] / vektorVorher[1];
	}
	else if (vektorVorher[2] != 0) {
		lambda = vektorNachher[2] / vektorVorher[2];
	}
	else {
		printf("Zero vector is always eigenvector (trivial)!\n");
	}

	// Check for eigenvectors 
	for (int i = 0; i < DIM; i++) {
		current = vektorVorher[i] * lambda - vektorNachher[i];
		current = (current > 0) ? current : -current;
		if (current > precision) {
			istEigenvektor = false;
		}
	}

	if (istEigenvektor) {
		printf("Eigenvektor zum Eigenwert %f\n", lambda);
	}
	else {
		printf("Kein Eigenvektor\n");
	}
}

// Diese Funktion gibt einen Vektor in der Kommandozeile aus
void printVektor(double vektor[DIM]) {
	printf("( ");
	int i = 0;
	for (i = 0; i < DIM; i++) {
		printf("%g ", vektor[i]);
	}
	printf(")\n");
}

int main(int argc, char *argv[]) {

	double matrix[DIM][DIM] = {
		{1., 2., 0.},
		{0., 3., 0.},
		{2., -4., 2.},
	};

	if (argc != 1 + DIM) {
		printf("Falsche Anzahl an Parametern\n");
		exit(1);
	}
	double vektor[DIM] = {atof(argv[1]), atof(argv[2]), atof(argv[3])};

	double ergebnis[DIM] = {0};
	matrixVektorMultiplikation(matrix, vektor, ergebnis);
	printf("Ergebnis der Matrix Multiplikation: ");
	printVektor(ergebnis);
	pruefeEigenvektor(vektor, ergebnis);

	return 0;
}
