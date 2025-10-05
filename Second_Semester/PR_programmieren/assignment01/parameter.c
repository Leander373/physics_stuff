#include <stdio.h> // Neue Bibliothek - benötigt für atof
#include <stdlib.h>
// AUTOR/IN: Leander Decristoforo

/* 
-when i divide by 0 the result is "inf", which probably stands for infinite;
-when i use letters i get 0, because the atof operation is returns a 0 when
 passing in a letter, i.e. the conversion fails, but if i start the string 
 with a number, it reads until it encounters a non-numeric input
-diciding 0 by 0 returns "-nan";
-witout enough (2) command line arguments, you get a seg-fault because there
 might not be any memory or argv[1] could be a NULL pointer
-the program already used float variables, so no need for any change
 */

int main(int argc, char *argv[]) {
	float z1, z2;

	// Einlesen der Seitenlängen
	z1 = atof(argv[1]);
	z2 = atof(argv[2]);

	// Berechnung
	float z3 = z1 + z2;

	// Ausgabe
	printf("Das Ergebnis von %f + %f ist %f\n", z1, z2, z3);

	return 0;
}