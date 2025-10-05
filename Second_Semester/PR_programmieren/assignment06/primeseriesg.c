#include <stdio.h>
#include <stdlib.h>
#define LIMIT 333

// Checks prime, 0 if, 1 if not
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Check for largest n with given a,b,c
long long largest_n(int a, int b, int c) {
    long long nmax = 0;
    long long result = 0;
    while (1) {
        result = (nmax * nmax * nmax) + a * (nmax * nmax) + b * nmax + c;
        if (!is_prime(result) || result < 2) {
            return nmax - 1;
        }
        nmax++;
    }
}

int main(void) {
    long long max = 0, current_n = 0;

    // Loop through every possible a,b and c
    for (int a = -LIMIT + 1; a < LIMIT; a++) {
        for (int b = -LIMIT; b < LIMIT; b++) {
            for (int c = -LIMIT; c < LIMIT; c++) {
                if(!is_prime(c)) {
                    continue;
                }
                // Compute largest n for a,b,c
                current_n = largest_n(a, b, c);
                if (current_n > max) {
                    max = current_n;
                }
            }
        }
    }
    fprintf(stdout, "The maximum value for n is %lld\n", max);
    return EXIT_SUCCESS;
}