#include <stdio.h>
// AUTOR/IN: Leander Decristoforo

/* Now the modulo doesn't work since you have to use integers for that, 
thus i converted the vlaues to integers (now it works); when running
the new program the values have floating point values now and the 
division worked*/ 

int main(void) {		// Good practice to use void, when no input (personal preference)

	float a = 21;
	float b = 10;
	float c;

	// Addiere a und b
	c = a + b;
	printf("Operation 1 - Das Ergebnis von %f + %f ist %f\n", a, b, c);
	
	// Subtrahiere b von a
	c = a - b;
	printf("Operation 2 - Das Ergebnis von %f - %f ist %f\n", a, b, c);
	
	// Multipliziere a und b
	c = a * b;
	printf("Operation 3 - Das Ergebnis von %f * %f ist %f\n", a, b, c);
	
	// Dividiere a und b
	c = a / b;
	printf("Operation 4 - Das Ergebnis von %f / %f ist %f\n", a, b, c);
	
	// a modulo b
	c = (int) a % (int) b;
	printf("Operation 5 - Das Ergebnis von %f mod %f ist %f\n", a, b, c);
	
	// Inkrementiere c
	printf("Operation 6 - Der Wert von c ist vorher %f\n", c);
	c++;
	printf("Operation 7 - Der Wert von c ist nachher %f\n", c);
	
	// Dekrementiere c
	printf("Operation 8 - Der Wert von c ist vorher %f\n", c);
	c--;
	printf("Operation 9 - Der Wert von c ist nachher %f\n", c);

	return 0;
}
