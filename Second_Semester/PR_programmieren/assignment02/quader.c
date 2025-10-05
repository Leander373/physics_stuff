#include <stdio.h>
#include <stdlib.h>

// BITTE AUSFÜLLEN:
// AUTOR: Leander Decristoforo

int main(int argc, char *argv[]) {
	float a, b, c;

	// Check for proper input
	if (argc != 4) {
		fprintf(stderr, "USAGE: ./quader <a> <b> <c>\n");
		return EXIT_FAILURE;
	}

	// Einlesen der Seitenlängen
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);

	// Berechnung der Oberfläche
	float oberflaeche = 0;
	oberflaeche += 2. * a * b; // <------ Kurzschreibweise zur Addition
	oberflaeche += 2. * a * c;
	oberflaeche += 2. * b * c;

	// Ausgabe
	printf("Ein Quader mit den Seitenlängen %f, %f und %f hat die Oberfläche %f\n",
		   a, b, c, oberflaeche);

	return 0;
}
