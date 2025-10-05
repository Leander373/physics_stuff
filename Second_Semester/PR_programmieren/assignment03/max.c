// AUTOR/IN: Leander Decristoforo

#include <stdio.h>
#include <stdlib.h>

// Funktionsdeklaration
int max(int number1, int number2);

// Main Funktion
int main(int argc, char *argv[]) {

	// Proper input 
	if (argc != 3) {
		fprintf(stderr, "USAGE: ./max <number1> <number2>\n");
		return EXIT_FAILURE;
	}

	// Variablendeklaration +  Initialisierung
	int zahl1 = 0, zahl2 = 0, maximum = 0;

	// Umwandlung der Eingabestrings in eine Ganzzahl
	zahl1 = atoi(argv[1]);
	zahl2 = atoi(argv[2]);

	// Funktionsaufruf der Funktion max()
	maximum = max(zahl1, zahl2);

	// Ausgabe des Ergebnisses
	printf("Die höhere Zahl ist: %i\n", maximum);

	return 0;
}

// Funktionsdefinition
int max(int number1, int number2) {
	// Geben Sie hier ihre Implementierung ein
	return (number1 > number2) ? number1 : number2;
}
