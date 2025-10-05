#include <stdio.h>
#include <stdlib.h>
// Authors: Mario Neuner, Leander Decristoforo

int main(void) {
    // Start at n 166 and m 144
    long n = 165, m = 144;       // 0 == not found, 1 == found
    long double sm = m * (2 * m -1), fn = 0;
    while (1) {
        // Calculate current sequence values
        fn = (n * (3 * n - 1)) / 2;
        // Go through elements of sm until >= fn
        while (fn > sm) {
            m++;
            sm = m * (2 * m -1);
        }
        // Check if sm equal to fn
        if (sm == fn) {
            break;
        }
        n++;
    }
    printf("The next same number are at m = %ld, n = %ld with fn = sm = %Lf (%Lf)\n", m, n, sm, fn);
    return EXIT_SUCCESS; 
}