// AUTOR/IN: Leander Decristoforo

/* I changed the input of the function to the pointer of the number */

#include <stdio.h>
#include <stdlib.h>

// Funktionsdeklaration
void hochdrei(int *zahl);

// Main Funktion
int main(int argc, char *argv[]) {

	// Check for proper usage
	if (argc != 2) {
		fprintf(stderr, "USAGE: ./hochdrei <number>\n");
		return EXIT_FAILURE;
	}

	int eingegebene_zahl = 0; // Initialisierung der Variable

	// Umwandlung des Eingabestrings in eine Ganzzahl
	eingegebene_zahl = atoi(argv[1]);

	// Function call
	printf("Wert vor Funktionsaufruf = %d\n", eingegebene_zahl);
	hochdrei(&eingegebene_zahl);
	printf("Wert nach Funktionsaufruf = %d\n", eingegebene_zahl);

	return 0;
}

// Funktionsdefinition
void hochdrei(int *zahl) {
	*zahl = (*zahl) * (*zahl) * (*zahl);
	// Ausgabe der lokalen Variablen a
	printf("Wert innerhalb der Funktion = %d\n", *zahl);
}
