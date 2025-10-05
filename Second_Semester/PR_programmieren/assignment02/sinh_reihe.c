#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

//Author: Leander Decristoforo

/* Exercise: 
Erstellen Sie ein Programm `sinh_reihe.c`, das den Sinus hyperbolicus mit Hilfe der Definition:

$\sinh\left(x\right) = \sum_{n=0}^\infty \frac{x^{2n+1}}{\left(2n+1\right)!} = x + \frac{x^3}{3!} + \frac{x^5}{5!} + ...$

berechnet. 
Sie müssen dafür *Unendlich* natürlich durch eine endliche Zahl ersetzen (experimentieren Sie zB. mit 100, 200, oder legen Sie eine Toleranz bzw. 
Genauigkeit fest. Sie können zum Beispiel testen, ob die Änderung durch den nächsten Term hinreichend klein ist). 
Es handelt sich also um eine numerische Näherung. 
*/

// Function for factorial
double factorial(int f) {
    double result = 1;
    for (int i = 1; i <= f; i++) {
        result *= i;
    }

    return result;
}

// Function for power
double power(double num, int pow) {
    double result = 1;
    for (int i = 0; i < pow; i++) {
        result *= num;
    }

    return result;
}

int main(int argc, char *argv[]) {
    // Define variables
    double x = 0, result = 0, current = 1;
    int i = 1, sign = 0;

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./sinh_reihe <number>\n");
        return EXIT_FAILURE;
    }

    x = atof(argv[1]);

    // Check if x < 0
    if (x < 0) {
        x *= -1;
        sign = 1;
    }

    // Loop for computing sinh
    do {
        current = power(x, i) / factorial(i);
        result += current;
        i += 2;
    } while (current > 0);

    //printf("%f\n", __DBL_MAX__);
    
    printf("sinh(%f) = %f\n", ((sign == 0) ? x : (-x)), ((sign == 0) ? result : (-result)));
    return EXIT_SUCCESS;
}
