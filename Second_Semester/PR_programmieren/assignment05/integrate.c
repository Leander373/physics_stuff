#include <stdio.h>
#include <stdlib.h>
// AUTOR/IN: Leander Decristforo
// You have to take at least 565 points so that the precision of the trapezoid rule is <= 0.0000010;

void ausgabe(double *array, int laenge);
double analytische_loesung(double a, double b);
double *erzeuge_intervall(double untere_grenze, double obere_grenze, int anzahl_punkte);
double *funktion_auswerten(double *x_werte, int anzahl_punkte);
double integral_berechnen(double *x_werte, double *y_werte, int anzahl_punkte);

int main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("Falsche Parameteranzahl, drei werden benötigt!\n");
		printf("untere und obere Integrationsgrenze sowie Anzahl der Punkte\n");
		exit(1);
	}

	double untere_grenze = atof(argv[1]);
	double obere_grenze = atof(argv[2]);
	int anzahl_punkte = atoi(argv[3]);

	// Sie können die folgenden Funktionen während des Testens einzeln aus und einkommentieren
	double *x_werte = erzeuge_intervall(untere_grenze, obere_grenze, anzahl_punkte);
	ausgabe(x_werte, anzahl_punkte);

	double *y_werte = funktion_auswerten(x_werte, anzahl_punkte);
	ausgabe(y_werte, anzahl_punkte);

	double loesung_analytisch = analytische_loesung(untere_grenze, obere_grenze);
	double loesung_numerisch = integral_berechnen(x_werte, y_werte, anzahl_punkte);
	printf("Das numerische Integral hat den Wert %.7lf. Der Fehler beträgt %.7lf.\n", loesung_numerisch, loesung_numerisch - loesung_analytisch);

	free(x_werte);
	free(y_werte);
	return 0;
}

void ausgabe(double *array, int laenge) {
	int i;
	if (array == NULL) {
		printf("Implementierung möglicherweise unvollständig, array ist NULL Zeiger\n");
	}
	else {
		for (i = 0; i < laenge; ++i) {
			printf("%f ", array[i]);
		}
		printf("\n");
	}
}

double analytische_loesung(double a, double b) {
	double result = (-a * a * a * a * a - 5 * a * a + b * b * b * b * b + 5 * b * b) / 5;
	return result;
}

double *erzeuge_intervall(double untere_grenze, double obere_grenze, int anzahl_punkte) {
	// Fügen Sie Ihre Lösung hier ein
	double distance = (obere_grenze - untere_grenze) / (anzahl_punkte - 1);

	// Allocate intervall
	double *intervall = malloc(anzahl_punkte * sizeof(double));
	if (intervall == NULL) {
		fprintf(stderr, "Not enough disk space for intervall!\n");
		return NULL;
	}

	// Initialize intervall
	for (int i = 0; i < anzahl_punkte; i++) {
		intervall[i] = untere_grenze + (i * distance);
	}
	return intervall; // und geben sie hier Ihr array zurück
}

double *funktion_auswerten(double *x_werte, int anzahl_punkte) {
	// Fügen Sie Ihre Lösung hier ein
	if (x_werte == NULL) {
		fprintf(stderr, "ERROR: Something went wrong, ups\n");
		return NULL;
	}

	// Allocate y value array
	double * y_werte = malloc(anzahl_punkte * sizeof(double));
	if (y_werte == NULL) {
		fprintf(stderr, "Not enough disk space for y_values\n");
		return NULL;
	}

	// Calculate y values
	for (int i = 0; i < anzahl_punkte; i++) {
		y_werte[i] = (x_werte[i] * x_werte[i] * x_werte[i] * x_werte[i]) + (2 * x_werte[i]);
	}
	return y_werte; // und geben sie hier Ihr array zurück
}

double integral_berechnen(double *x_werte, double *y_werte, int anzahl_punkte) {
	// Fügen Sie Ihre Lösung hier ein
	double solution = 0;

	for (int i = 0; i < anzahl_punkte - 1; i++) {
		solution += (x_werte[i + 1] - x_werte[i]) * ((y_werte[i + 1] + y_werte[i]) / 2);
	}
	return solution; // und geben sie hier Ihren Integralwert zurück
}
