#include <stdio.h>
#include <stdlib.h>

//Author: Leander Decristoforo

/* Exercise: 
Kopieren Sie nun Ihr Programm aus Teilaufgabe c in die Datei 
fakultaet_long.c und verwenden Sie statt des Datentyps int den Datentyp long 
(CAVEAT: Dies hat Auswirkungen an mehreren Stellen im Programm!).
Wie verhält sich jetzt der Speicherbereich und welche maximale Fakultät können Sie berechnen?
Vermerken Sie diese Zahlen am Ende des Quellcodes in einem Kommentar.
Es gibt natürlich noch weitere Datentypen. Diese können Sie bei Bedarf gerne im Internet recherchieren 
*/

int main(int argc, char *argv[]) {
    long number = 1, input = 0;

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
    printf("Die Fakultaet von %li ist %li\n", input, number);
    printf("Anzahl der Bytes von zahl: %li\n", sizeof(number));

    return EXIT_SUCCESS;
}

/* The long now takes 8 Bytes space and the maximum number is 20 
(20! = 2432902008176640000) */