#include <stdio.h>
#include <stdlib.h>

//Author: Leander Decristoforo

/*Exercise: Legen Sie eine neue Quellcodedatei mit dem Namen `fakultaet.c` an. 
Programmieren Sie darin ein Programm, das die Fakultät einer, 
mittels Parameter im Terminal übergebenen, ganzen Zahl berechnet. 
Überprüfen Sie vorher noch, dass genau ein Parameter übergeben wurde 
und geben Sie andernfalls einen Hinweis aus.
Stimmen die Ergebnisse? Ab welcher Zahl stimmt das Ergebnis nicht mehr?
Vermerken Sie diese Zahlen am Ende des Quellcodes in einem Kommentar.*/

int main(int argc, char *argv[]) {
    int number = 1, input = 0;

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./fakultaet <number>\n");
        return EXIT_FAILURE;
    }

    input = atoi(argv[1]);

    // Compute factorial
    for (int i = 1; i <= input; i++) {
        number *= i;
    }

    // Output number and count of bytes
    printf("Die Fakultaet von %i ist %i\n", input, number);
    printf("Anzahl der Bytes von zahl: %li\n", sizeof(number));

    return EXIT_SUCCESS;
}

/* The max number with correct output is 12, in other words, you get 
the first wrong output with 13 */