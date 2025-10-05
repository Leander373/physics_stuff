#include <stdio.h>
// AUTOR/IN: Leander Decristoforo

/* When running the program everything seems fine except the division, because we use integers 
and thus every floating point gets dumped, in other words, we get an integer again */ 

int main(void) {		// Good practice to use void, when no input (personal preference)

	int a = 21;
	int b = 10;
	int c;

	// Addiere a und b
	c = a + b;
	printf("Operation 1 - Das Ergebnis von %i + %i ist %i\n", a, b, c);
	
	// Subtrahiere b von a
	c = a - b;
	printf("Operation 2 - Das Ergebnis von %i - %i ist %i\n", a, b, c);
	
	// Multipliziere a und b
	c = a * b;
	printf("Operation 3 - Das Ergebnis von %i * %i ist %i\n", a, b, c);
	
	// Dividiere a und b
	c = a / b;
	printf("Operation 4 - Das Ergebnis von %i / %i ist %i\n", a, b, c);
	
	// a modulo b
	c = a % b;
	printf("Operation 5 - Das Ergebnis von %i mod %i ist %i\n", a, b, c);
	
	// Inkrementiere c
	printf("Operation 6 - Der Wert von c ist vorher %i\n", c);
	c++;
	printf("Operation 7 - Der Wert von c ist nachher %i\n", c);
	
	// Dekrementiere c
	printf("Operation 8 - Der Wert von c ist vorher %i\n", c);
	c--;
	printf("Operation 9 - Der Wert von c ist nachher %i\n", c);

	return 0;
}
