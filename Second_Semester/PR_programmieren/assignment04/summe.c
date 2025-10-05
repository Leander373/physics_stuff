#include <stdio.h>
// Autor: Leander Decristoforo

// Funktionsdeklaration
float summe(float array[], int n);

// Main program
int main(void) {
	int laenge = 10;
	float liste[laenge];

	for (int i = 0; i < laenge; i++) {		// Array starts at index 0 and ends at length - 1 => first ellement uninitialized (could be any number)
		liste[i] = 0.1 * (i + 1);
	}

	// Funktionsaufruf
	float ergebnis = summe(liste, laenge);

	printf("Die Summe ist: %f, wir erwarten als Ergebnis %f\n", ergebnis, 5.5);

	return 0;
}

// Funktionsdefinition
float summe(float array[], int n) {		// Function returns float now for proper solution
	float summe = 0;

	for (int i = 0; i < n; i++) { // An array starts with index 0 and ends with length - 1
		summe += array[i];
	}
	return summe;
}
