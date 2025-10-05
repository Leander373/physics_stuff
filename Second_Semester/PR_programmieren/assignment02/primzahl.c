#include <stdio.h>
#include <stdlib.h>

//Author: Leander Decristoforo

/* Exercise: 
Erstellen Sie nun ein Programm `primzahl.c`, das überprüft ob eine übergebene Zahl eine Primzahl ist.
Dazu werden Sie natürlich eine Schleife und `if/else` benötigen.
Um das Programm schneller zu machen, empfiehlt es sich die Schleife mit `break;` abzubrechen, 
wenn es den ersten Beweis dafür gibt, dass es sich nicht um eine Primzahl handelt. 
*/

int main(int argc, char *argv[]) {
    long number = 0, check = 2;

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./primzahl <number>\n");
        return EXIT_FAILURE;
    }

    number = atoi(argv[1]);

    // Compute factorial
    while (check * check <= number) {
        if ((number % check) == 0) {
            printf("The number %li is not prime\n", number);
            return EXIT_SUCCESS;
        }
        check++;
    }

    // Output number and count of bytes
    printf("The number %li is prime\n", number);

    return EXIT_SUCCESS;
}
