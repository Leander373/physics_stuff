#include <stdio.h>
#include <stdlib.h>

// Author: Leander Decristoforo

/* Exercise: Clonen Sie wie üblich das Repository zur heutigen Teilaufgabe auf Ihren Rechner.
Legen Sie eine neue Quellcodedatei mit dem Namen vergleich.c an.
Programmieren Sie darin ein Programm, das die Information darüber zurück gibt, 
ob von zwei übergebenen Ganzzahlen die erste oder die zweite Zahl größer ist, oder ob beide gleich sind.
*/

int main(int argc, char *argv[]) {
    int a = 0, b = 0;
    
    // Ceck proper usage
    if(argc != 3) {
        fprintf(stderr, "USAGE: ./vergleich <int> <int>\n");
        return EXIT_FAILURE;
    }

    // Convert input
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    // Print output
    if (a > b) {
        fprintf(stdout, "The number %i is bigger than %i\n", a, b);
    }
    else if (a < b) {
        fprintf(stdout, "The number %i is less than %i\n", a, b);
    }
    else {
        fprintf(stdout, "The numbers %i and %i are equal\n", a, b);
    }

    return EXIT_SUCCESS;
}